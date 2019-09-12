<!DOCTYPE html>
<html lang="en">
	<head>
 		<meta charset="UTF-8">
	
		<title>
			Snoop Dogg - Official
		</title>
			<link rel="stylesheet" type="text/css" href="estilo/estilo.css">
            <link rel="icon" href="imagenes/snoop_ico.ico" type="image/ico">
            <script src="https://code.jquery.com/jquery-3.3.1.min.js"></script>
            <script src="include.js"></script>
	
       <script>    
        // Todo el menu de control tanto de admin como gestor se carga con AJAX
            $(document).ready(function(){
                $(".menu").click(function(){ // Segun donde pinche en el menu
                    var data = $(this).attr('id'); //El id del elemento es la variable POST para que nos devuelva la info
                    
                    $.ajax({
                            type : "POST",
                            url  : 'database/formularios_gestion.php',//Segun el POST, devuelve el contenido (concierto, discos, pedidos...)
                            data : data,
                            success: function(result) {
                                
                                $("#imprimirAqui").html(result); //Imprimimos el resultado

                            }       
                    });
                });
            });

        </script>
    
    </head>
		<!--
                IMPORTANTE: 

                gestion.php no imprime ningun formulario, su función es imprimir el menu para que con AJAX se imprima
                la opcion correspondiente, que puede ser modificar articulos, discografia, administrar usuarios...
                este html se encuentra en formularios_gestion.php y segun donde el usuario pinche sobre el menu, se hace un
                POST con AJAX con el id del elemento del menu como variable. En formularios_gestion.php se devuelven
                los formularios que generalmente son 2, añadir y modificar. El formulario de añadir se evalua en gestion.php
                donde se hacen las inserciones, y el de modificar tiene como acción el fichero modificar.php, donde según
                las variables POST se hace lo correspondiente (parecido a formularios_gestion.php)

        -->
			
            <!-- ---------------------------------------------------------- -->
        <?php

            session_start();
            
        if($_SESSION['tipo'] == 'admin'){
                
            require_once 'database/conexion.php';
            // El menu lo cargamos con AJAX
            echo '<section id="opciones_l_prev">
                    <section class="titulo_info">
                                    <h2> Menú </h2>
                        </section>
                    <section id="opciones_l">
                            <button type="button" class="menu" id="articulos"> Modificar artículos </button>
                            <button type="button" class="menu" id="discos"> Modificar discografía </button>
                            <button type="button" class="menu" id="conciertos"> Modificar conciertos </button>
                            <button type="button" class="menu" id="componentes"> Modificar componentes </button>
                            <button type="button" class="menu" id="biografia"> Modificar biografía </button>
                            <button type="button" class="menu" id="usuarios"> Administrar usuarios </button>
                            <button type="button" class="menu" id="logs"> Ver logs de la aplicación </button>
                            <button type="button" class="menu" id="backup"> Backup de la BD </button>
                            <a href="index.php"> <button type="button" class="menu">Volver a inicio </button></a>
                    </section>
                </section>

                ';

                                
                // ARTICULOS - AÑADIR
                if(isset($_POST["nombre_articulo"]) &&
                    isset($_POST["precio_articulo"])          
                ){

                    $target_dir = "imagenes_subidas/articulos/";
                    $target_file = $target_dir . basename($_FILES["foto_articulo"]["name"]);
                   
                    // Validamos con JS
                    echo '<script> validarTexto('.$_POST['nombre_articulo'].');  </script>';
                    echo '<script> validarNumero('.$_POST['precio_articulo'].');  </script>';
                    

                    if (file_exists($target_file)) {
                        echo "<script> alert('La imagen ya existe'); </script>";
                    }else{

                        if (move_uploaded_file($_FILES["foto_articulo"]["tmp_name"], $target_file)) {

                            $nombre = $mysqli->real_escape_string($_POST['nombre_articulo']);
                            $precio = $mysqli->real_escape_string($_POST['precio_articulo']);
                            $tipo = $mysqli->real_escape_string($_POST['tipo']);

                            $sql = "INSERT INTO `articulos` (foto, nombre, precio, tipo) VALUES ('$target_file', '$nombre', '$precio', '$tipo');";
                            guardarLogs($sql); // Guardamos logs
                            $mysqli->query($sql) or die($mysqli->error);

                        } 
                    }
                    
                    unset($_POST['nombre_articulo']);
                    unset($_POST['precio_articulo']);

                }

                // DISCOS - añadir
                if(isset($_POST["nombre_disco"]) &&
                    isset($_POST["año_disco"])          
                ){

                    $target_dir = "imagenes_subidas/discos/";
                    $target_file = $target_dir . basename($_FILES["foto_disco"]["name"]);
                   

                    echo '<script> validarTexto('.$_POST['nombre_disco'].');  </script>';
                    echo '<script> validarNumero('.$_POST['año_disco'].');  </script>';

                    if (file_exists($target_file)) {
                        echo "<script> alert('La imagen ya existe'); </script>";
                    }else{

                        if (move_uploaded_file($_FILES["foto_disco"]["tmp_name"], $target_file)) {

                            $nombre = $mysqli->real_escape_string($_POST['nombre_disco']);
                            $año = $mysqli->real_escape_string($_POST['año_disco']);

                            $sql = "INSERT INTO `discos` (foto, nombre, year_s) VALUES ('$target_file', '$nombre', '$año');";
                            guardarLogs($sql);
                            $mysqli->query($sql) or die($mysqli->error);

                        } 
                    }
                    
                

                }

                // CONCIERTOS
                if(isset($_POST["nombre_concierto"]) &&
                    isset($_POST["fecha_concierto"]) &&
                    isset($_POST['hora_concierto'])  &&
                    isset($_POST['lugar_concierto']) &&
                    isset($_POST['descripcion_concierto']) 
                    ){

                    $target_dir = "imagenes_subidas/conciertos/";
                    $target_file = $target_dir . basename($_FILES["cartel"]["name"]);
                

                    

                    if (file_exists($target_file)) {
                        echo "<script> alert('La imagen ya existe'); </script>";
                    }else{

                        if (move_uploaded_file($_FILES["cartel"]["tmp_name"], $target_file)) {

                            $nombre = $mysqli->real_escape_string($_POST['nombre_concierto']);
                            $fecha = $mysqli->real_escape_string($_POST['fecha_concierto']);
                            $hora = $mysqli->real_escape_string($_POST['hora_concierto']);
                            $lugar = $mysqli->real_escape_string($_POST['lugar_concierto']);
                            $descripcion = $mysqli->real_escape_string($_POST['descripcion_concierto']);

                            $sql = "INSERT INTO `conciertos` (cartel, fecha, hora, lugar, nombre, descripcion) VALUES ('$target_file', '$fecha', '$hora', '$lugar', '$nombre', '$descripcion');";
                            guardarLogs($sql);
                            $mysqli->query($sql) or die($mysqli->error);

                        } 
                    }
                    
                

                }


                // COMPONENTE
                if(isset($_POST["nombre_componente"]) &&
                isset($_POST["fecha_nacimiento"]) &&
                isset($_POST['bio_componente'])  
                ){

                    $target_dir = "imagenes_subidas/componentes/";
                    $target_file = $target_dir . basename($_FILES["foto_componente"]["name"]);
                

                    

                    if (file_exists($target_file)) {
                        echo "<script> alert('La imagen ya existe'); </script>";
                    }else{

                        if (move_uploaded_file($_FILES["foto_componente"]["tmp_name"], $target_file)) {

                            $nombre = $mysqli->real_escape_string($_POST['nombre_componente']);
                            $fecha = $mysqli->real_escape_string($_POST['fecha_nacimiento']);
                            $bio = $mysqli->real_escape_string($_POST['bio_componente']);

                            $sql = "INSERT INTO `componentes` (nombre, nacimiento, foto, bio_componente) VALUES ('$nombre', '$fecha', '$target_file', '$bio');";
                            guardarLogs($sql);
                            $mysqli->query($sql) or die($mysqli->error);

                        } 
                    }
                }

                // BIOGRAFÍA
                if(isset($_POST["biografia_texto"])) {
                    
                    $bio = $mysqli->real_escape_string($_POST['biografia_texto']);
                    $id = "NULL";
                   
                    if(isset($_POST['year_bio'])){
                       $fecha = $mysqli->real_escape_string($_POST['year_bio']);
                       $sql = "INSERT INTO `biografia` (id, fecha, texto) VALUES ('$id', '$fecha', '$bio');";
                   } else{
                       $fecha = "";
                        $sql = "INSERT INTO `biografia` (id, fecha, texto) VALUES ('$id', '$fecha', '$bio');";
                   }

                        guardarLogs($sql);
                        $mysqli->query($sql) or die($mysqli->error);

                }
            

                // USUARIOS

                if(isset($_POST["nombre_persona"]) &&
                isset($_POST["apellidos_persona"]) &&
                isset($_POST['telf_persona']) &&
                isset($_POST['email_persona']) &&
                isset($_POST['pass_persona'])
                ){

                    echo '<script> validarTexto('.$_POST['nombre_persona'].');  </script>';
                    echo '<script> validarTexto('.$_POST['apellidos_persona'].');  </script>';
                    echo '<script> validarEmail('.$_POST['email_persona'].');  </script>';
                    
                    // Evitar injeccion SQL
                    $nombre = $mysqli->real_escape_string($_POST['nombre_persona']);
                    $apellidos = $mysqli->real_escape_string($_POST['apellidos_persona']);
                    $telf = $mysqli->real_escape_string($_POST['telf_persona']);
                    $email = $mysqli->real_escape_string($_POST['email_persona']);
                    $pass = $mysqli->real_escape_string($_POST['pass_persona']);
                    $pass =  base64_encode($pass);


                    if(isset($_POST['tipo_persona'])){
                        if($_POST['tipo_persona'] == 'admin'){
                            $sql = "INSERT INTO `admins` (nombre, apellidos, telefono, email, clave_cifrada) VALUES ('$nombre', '$apellidos', '$telf', '$email', '$pass');";
                            $tipo = 'admin';
                            $sql2 = "INSERT INTO `usuarios` (email, clave_cifrada, tipo) VALUES ('$email', '$pass', '$tipo' );";
                        }else if($_POST['tipo_persona'] == 'gestor'){
                            $sql = "INSERT INTO `gestores` (nombre, apellidos, telefono, email, clave_cifrada) VALUES ('$nombre', '$apellidos', '$telf', '$email', '$pass');";
                            $tipo = 'gestor';
                            $sql2 = "INSERT INTO `usuarios` (email, clave_cifrada, tipo) VALUES ('$email', '$pass', '$tipo' );";
                        }
                        guardarLogs($sql);
                        guardarLogs($sql2);
                        $mysqli->query($sql) or die($mysqli->error);
                        $mysqli->query($sql2) or die($mysqli->error);
                    }
                }



        }else if($_SESSION['tipo'] == 'gestor'){

            require_once 'database/conexion.php';
            // Menu para gestor
            echo '<section id="opciones_l_prev">
                    <section class="titulo_info">
                                    <h2> Menú </h2>
                        </section>
                    <section id="opciones_l">
                            <button type="button" class="menu" id="pendientes"> Peticiones pendientes </button>
                            <button type="button" class="menu" id="peticiones"> Historial de peticiones </button>
                            <button type="button" class="menu" id="precio"> Modificar precio </button>
                            <a href="index.php"> <button type="button" class="menu">Volver a inicio </button></a>
                    </section>
                </section>

                ';

        }else{
                   
                header("Location: index.php");
            }


            ?>

            <section id="imprimirAqui"> <!-- Imprimimos lo que nos devuelve formularios_gestion.php -->
            </section>

			
			<!-- ---------------------------------------------------------- -->	
			<br>
		<hr class="separador">
	<footer>
		<nav id="fin" class="centrado"> 
			 <a href="index.php"> Inicio </a> 
			 <a href=""> Copyright 2018 </a> 
			  <a href="Documentacion.pdf"> Documentación </a>  
		</nav>
	</footer>


			

	</body>
</html>
