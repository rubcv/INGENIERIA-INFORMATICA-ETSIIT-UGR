<!DOCTYPE html>
<html lang="en">
	<head>
 		<meta charset="UTF-8">
	
		<title>
			Snoop Dogg - Official
		</title>
			<link rel="stylesheet" type="text/css" href="estilo/estilo.css">
            <script src="https://code.jquery.com/jquery-3.3.1.min.js"></script>
	
       <script>    
            $(document).ready(function(){
                $(".menu").click(function(){
                    var data = $(this).attr('id'); 
                    
                    $.ajax({
                            type : "POST",
                            url  : 'database/formularios_gestion.php',
                            data : data,
                            success: function(result) {
                                
                                $("#imprimirAqui").html(result);

                            }       
                    });
                });
            });

        </script>
    
    </head>
		
			
            <!-- ---------------------------------------------------------- -->
        <?php

            session_start();
            
        if($_SESSION['tipo'] == 'admin'){
                
            require_once 'database/conexion.php';
            
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
                            <a href="index.php"> <button type="button" class="menu">Volver a inicio </button></a>
                    </section>
                </section>

                ';

                                
                // ARTICULOS
                if(isset($_POST["nombre_articulo"]) &&
                    isset($_POST["precio_articulo"])          
                ){

                    $target_dir = "imagenes_subidas/articulos/";
                    $target_file = $target_dir . basename($_FILES["foto_articulo"]["name"]);
                   

                    

                    if (file_exists($target_file)) {
                        echo "<script> alert('La imagen ya existe'); </script>";
                    }else{

                        if (move_uploaded_file($_FILES["foto_articulo"]["tmp_name"], $target_file)) {

                            $nombre = $mysqli->real_escape_string($_POST['nombre_articulo']);
                            $precio = $mysqli->real_escape_string($_POST['precio_articulo']);
                            $tipo = $mysqli->real_escape_string($_POST['tipo']);

                            $sql = "INSERT INTO `articulos` (foto, nombre, precio, tipo) VALUES ('$target_file', '$nombre', '$precio', '$tipo');";
                        
                            $mysqli->query($sql) or die($mysqli->error);

                        } 
                    }
                    
                    unset($_POST['nombre_articulo']);
                    unset($_POST['precio_articulo']);

                }

                // DISCOS
                if(isset($_POST["nombre_disco"]) &&
                    isset($_POST["año_disco"])          
                ){

                    $target_dir = "imagenes_subidas/discos/";
                    $target_file = $target_dir . basename($_FILES["foto_disco"]["name"]);
                   

                    

                    if (file_exists($target_file)) {
                        echo "<script> alert('La imagen ya existe'); </script>";
                    }else{

                        if (move_uploaded_file($_FILES["foto_disco"]["tmp_name"], $target_file)) {

                            $nombre = $mysqli->real_escape_string($_POST['nombre_disco']);
                            $año = $mysqli->real_escape_string($_POST['año_disco']);

                            $sql = "INSERT INTO `discos` (foto, nombre, year_s) VALUES ('$target_file', '$nombre', '$año');";
                        
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

                    
                        $mysqli->query($sql) or die($mysqli->error);

                }
            

                // USUARIOS

                if(isset($_POST["nombre_persona"]) &&
                isset($_POST["apellidos_persona"]) &&
                isset($_POST['telf_persona']) &&
                isset($_POST['email_persona']) &&
                isset($_POST['pass_persona'])
                ){

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
                        
                        $mysqli->query($sql) or die($mysqli->error);
                        $mysqli->query($sql2) or die($mysqli->error);
                    }
                }



        }else if($_SESSION['tipo'] == 'gestor'){
                    echo '<section class="titulo_info">
                            <h2> Modificar precio a artículo </h2>
                        </section>';



                    echo '<section class="titulo_info">
                            <h2> Gestionar pedidos </h2>
                         </section>';
               
        }else{
                   
                header("Location: index.php");
            }


            ?>

            <section id="imprimirAqui">
            </section>

			
			<!-- ---------------------------------------------------------- -->	
			<br>
		<hr class="separador">
	<footer>
		<nav id="fin" class="centrado"> 
			 <a href="index.php"> Inicio </a> 
			 <a href=""> Copyright 2018 </a> 
			 <a href=""> Mapa del sitio </a> 
		</nav>
	</footer>


			

	</body>
</html>
