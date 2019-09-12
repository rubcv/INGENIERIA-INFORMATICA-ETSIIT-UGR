<!DOCTYPE html>
<html lang="en">
	<head>
 		<meta charset="UTF-8">
	
		<title>
			Snoop Dogg - Official
		</title>
			<link rel="stylesheet" type="text/css" href="estilo/estilo.css">
	</head>
	<body>
		<div class="parallax">
		<section id="cabecera" class="centrado">
			<img src="imagenes/snoopletters.png" alt="Snoop">
			<header>
				<h1> 
					Official Site
				</h1>
			</header>
		</section>
			</div>
			
			<section id="fondo-navegacion">
				<section id="navegacion"> 
						<a href="index.php">  <p class="contenido"> Inicio  </p> </a>  <br>
					 	<a href="biografia.php"> <p class="contenido"> Biografía  </p> </a> <br>					
						<a href="discografia.php"> <p class="contenido"> Discografía </p> </a> <br>		
						<a href="tienda.php"> <p class="contenido"> Tienda </p> </a> <br>	
						
						<?php 

						session_start();
						
						if(isset($_SESSION['nombre'])){
							echo '<p id="sesion_header"> <strong> Saludos ' . $_SESSION['nombre'] . ' - sesión iniciada como ' . $_SESSION['tipo'] . '<a href="database/logout.php"> (click aqui para cerrar sesión) </a> </strong></p> <br>	';
							echo '<a href="gestion.php"> <p class="contenido">  &#8614;<strong> Ir al panel de gestión </strong></p> </a> <br>';	
						}else{
							echo '<a href="login.php"> <p class="contenido"> <strong> Iniciar sesión - Registrarme </strong></p> </a> <br>';	
						}
						?>
					</nav>
				</section>
			</section>		
			
			<!-- ---------------------------------------------------------- -->
            <?php

                require_once 'database/conexion.php';
                                

                if($_SESSION['tipo'] == 'admin'){
                    

                    // ARTICULOS
                    if(isset($_POST['nombre_articulo_mod']) &&
                        isset($_POST['precio_articulo_mod'])){


                            $nombre = $_POST['nombre_articulo_mod'];
                            
                            $sql = "SELECT * FROM `articulos` WHERE nombre = '$nombre';";
                            
                            $result =  $mysqli->query($sql) or die($mysqli->error);
                            
                            $row = $result->fetch_row();

                            $foto = $row[0];
                            $precio = $row[2];
                            echo '<br><br><form class="login_form" action="modificar.php" method="POST" enctype="multipart/form-data">
                                    <img src="'. $foto. '" class="slides" alt="articulo"><br><br> 
                                Nombre del artículo <br> <input type="text" name="nombre_articulo_modificado" value="'.$nombre.'"> <br><br>
                                   Precio <br> <input type="number" name="precio_articulo_modificado" value="'.$precio.'">&nbsp; &euro; <br><br>
                                   Foto del artículo  <input type="file" name="foto_articulo_modificada" id="foto_articulo"> <br><br>
                                    <input type="hidden" name="nombre_anterior" value="'.$nombre.'">
                                   Disco <input type="radio" name="tipo" value="disco">
                                   Merchandising <input type="radio" name="tipo" value="merch"> <br><br>
                                   <input type="submit" value="Modificar">
                                </form>
                            ';

                            echo '<form class="login_form delete" action="modificar.php" method="POST" enctype="multipart/form-data">
                                    <input type="hidden" name="nombre_anterior" value="'.$nombre.'"> 
                                    <input type="hidden" name="borrar" value="borrar">
                                    <input type="submit" value="Borrar">
                                </form>
                            ';
                    }

                    
                    if(isset($_POST['nombre_articulo_modificado']) &&
                    isset($_POST['precio_articulo_modificado'])){
                        
                        if(preg_match('/\d/', $_POST['nombre_articulo_modificado']) || !preg_match('/[0-9]/', $_POST['precio_articulo_modificado'])){
                            header("Location: gestion.php");
                        }
                        
                            $nombre_anterior = $_POST['nombre_anterior'];
                            
                            
                            
                             $target_dir = "imagenes_subidas/articulos/";
                            $target_file = $target_dir . basename($_FILES["foto_articulo_modificada"]["name"]);
                        
        
                            if (file_exists($target_file)) {
                               
                                
                                if (move_uploaded_file($_FILES["foto_articulo_modificada"]["tmp_name"], $target_file)) {
        
        
                                    $sql = "UPDATE `articulos` SET `foto` = '$target_file' WHERE `articulos`.`nombre` = '$nombre_anterior'";
                                    $mysqli->query($sql) or die($mysqli->error);
        
                                } 
                            }
                            

                            $nuevo_nombre = $_POST['nombre_articulo_modificado'];
                            $nuevo_precio = $_POST['precio_articulo_modificado'];
                            $sql = "UPDATE `articulos` SET `nombre` = '$nuevo_nombre', `precio` = '$nuevo_precio' WHERE `articulos`.`nombre` = '$nombre_anterior'";
                            $mysqli->query($sql) or die($mysqli->error);
                            
                            header("Location: gestion.php");
                    
                    }

                    if(isset($_POST['borrar'])){
                        $nombre_anterior = $_POST['nombre_anterior'];
                        
                        $sql = "SELECT * FROM `articulos` WHERE nombre = '$nombre_anterior';";
                    
                        $result =  $mysqli->query($sql) or die($mysqli->error);
                        $row = $result->fetch_row(); 
                        $foto = $row[0];
                       
                        unlink($foto);

                        $sql = "DELETE FROM `articulos` WHERE `articulos`.`nombre` = '$nombre_anterior';";
                        $mysqli->query($sql) or die($mysqli->error);
                            
                        header("Location: gestion.php");
                    
                    }


                    // DISCOS

                    if(isset($_POST['nombre_disco_mod']) &&
                    isset($_POST['año_mod'])){


                        $nombre = $_POST['nombre_disco_mod'];
                        
                        $sql = "SELECT * FROM `discos` WHERE nombre = '$nombre';";
                        
                        $result =  $mysqli->query($sql) or die($mysqli->error);
                        
                        $row = $result->fetch_row();

                        $foto = $row[0];
                        $year = $row[2];
                        echo '<br><br><form class="login_form" action="modificar.php" method="POST" enctype="multipart/form-data">
                                <img src="'. $foto. '" class="slides" alt="articulo"><br><br> 
                             Nombre:<br> <input type="text" name="nombre_disco_modificado" value="'.$nombre.'"> <br><br>
                                Año:<br> <input type="number" name="year_disco_modificado" value="'.$year.'"> <br><br>
                               Foto del artículo  <input type="file" name="foto_disco_modificada" id="foto_disco_modificada"> <br><br>
                                <input type="hidden" name="nombre_anterior_disco" value="'.$nombre.'">
                               <input type="submit" value="Modificar">
                            </form>
                        ';

                        $sql = "SELECT * FROM `canciones` WHERE disco = '$nombre'";
                       
                        $result =  $mysqli->query($sql) or die($mysqli->error);
                        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
                    
                        if(!empty($campos)){
                            
                            echo '<section id="canciones_lista">';
                            echo '<h3 id="canciones"> Canciones </h3>';
                            for ($i=0; $i < sizeof($campos) ; $i++) { 
                                echo $campos[$i]['nombre'] . " (" . $campos[$i]['duracion'] . ")<br>";
                            }
                            echo '</section>';

                        }

                        echo '<br><form class="login_form" action="modificar.php" method="POST">
                            <input type="hidden" name="nombre_anterior_disco" value="'.$nombre.'">
                            Escribe núm. de canciones a añadir <br><br><input type="text" name="canciones_disco" id="canciones_disco"><br>
                            <a href="#" id="llenarCanciones" onclick="addCanciones()"> Click para añadir </a> <br><br>
                            <div id="contenedor"/>
                            </form>
                        ';

                        echo '<script>
                                function addCanciones(){
                                    var cantidad = document.getElementById("canciones_disco").value;
                                    var contenedor = document.getElementById("contenedor");

                                    while(contenedor.hasChildNodes()){
                                        contenedor.removeChild(contenedor.lastChild);
                                    }

                                    for(i = 0; i < cantidad; i++){
                                        contenedor.appendChild(document.createTextNode("Cancion " + (i+1) + " nombre: "));

                                        var input = document.createElement("input");
                                        input.type = "text";
                                        input.name = "cancion[]";

                                        contenedor.appendChild(input);

                                        var duracion = document.createElement("input");
                                        duracion.type = "text";
                                        duracion.name = "duracion[]";
                                        contenedor.appendChild(document.createTextNode(" duración: (00:00) "));
                                        contenedor.appendChild(duracion);

                                        contenedor.appendChild(document.createElement("br"));
                                        contenedor.appendChild(document.createElement("br"));
                                    } 
                                    var enviar = document.createElement("input");
                                    enviar.setAttribute("type", "submit");
                                    enviar.setAttribute("value", "Añadir canciones");
                                    contenedor.appendChild(enviar);
                                
                                }
                        </script>';

                        echo '<form class="login_form delete" action="modificar.php" method="POST" enctype="multipart/form-data">
                                <input type="hidden" name="nombre_anterior_disco" value="'.$nombre.'"> 
                                <input type="hidden" name="borrar_disco" value="borrar">
                                <input type="submit" value="Borrar">
                            </form>
                        ';
                }

                
                if(isset($_POST['nombre_disco_modificado']) &&
                isset($_POST['year_disco_modificado'])){
                    
                    if(preg_match('/\d/', $_POST['nombre_disco_modificado']) || !preg_match('/[0-9]/', $_POST['year_disco_modificado'])){
                        header("Location: gestion.php");
                    }
                    
                        $nombre_anterior = $_POST['nombre_anterior_disco'];
                        
                        
                        
                         $target_dir = "imagenes_subidas/discos/";
                        $target_file = $target_dir . basename($_FILES["foto_disco_modificada"]["name"]);
                    
    
                        if (!file_exists($target_file)) {
                           
                            
                            if (move_uploaded_file($_FILES["foto_disco_modificada"]["tmp_name"], $target_file)) {
    
    
                                $sql = "UPDATE `discos` SET `foto` = '$target_file' WHERE `discos`.`nombre` = '$nombre_anterior'";
                                $mysqli->query($sql) or die($mysqli->error);
    
                            } 
                        }
                        

                        $nuevo_nombre = $_POST['nombre_disco_modificado'];
                        $nuevo_year = $_POST['year_disco_modificado'];
                        $sql = "UPDATE `discos` SET `nombre` = '$nuevo_nombre', `year_s` = '$nuevo_year' WHERE `discos`.`nombre` = '$nombre_anterior'";
                        $mysqli->query($sql) or die($mysqli->error);
                        
                        header("Location: gestion.php");
                
                    }

                if(isset($_POST['borrar_disco'])){
                    $nombre_anterior = $_POST['nombre_anterior_disco'];
                    
                    $sql = "SELECT * FROM `discos` WHERE nombre = '$nombre_anterior';";
                    
                    $result =  $mysqli->query($sql) or die($mysqli->error);
                    $row = $result->fetch_row(); 
                    $foto = $row[0];
                   
                    unlink($foto);
                    
                    $sql = "DELETE FROM `discos` WHERE `discos`.`nombre` = '$nombre_anterior';";
                    $mysqli->query($sql) or die($mysqli->error);
                        
                    header("Location: gestion.php");
                
                }


                if(isset($_POST['cancion']) &&
                    isset($_POST['duracion'])){
                        
                        $nombre_anterior = $_POST['nombre_anterior_disco'];

                        for ($i=0; $i < sizeof($_POST['cancion']) ; $i++) { 
                            $cancion = $_POST['cancion'][$i];
                            $duracion = $_POST['duracion'][$i];

                           $sql = "INSERT INTO `canciones` (disco, nombre, duracion) VALUES ('$nombre_anterior', '$cancion', '$duracion');";
                          
                           $mysqli->query($sql) or die($mysqli->error);
                        }
                        header("Location: gestion.php");
                }
                


                // CONCIERTOS
                if(isset($_POST['nombre_concierto_mod']) &&
                isset($_POST['fecha_concierto_mod']) &&
                isset($_POST['hora_concierto_mod']) &&
                isset($_POST['lugar_concierto_mod']) &&
                isset($_POST['descripcion_concierto_mod']) 
                ){


                    $nombre = $_POST['nombre_concierto_mod'];
                    
                    $sql = "SELECT * FROM `conciertos` WHERE nombre = '$nombre';";
                    
                    $result =  $mysqli->query($sql) or die($mysqli->error);
                    
                    $row = $result->fetch_row();

                    $cartel = $row[0];
                    $fecha = $row[1];
                    $hora = $row[2];
                    $lugar = $row[3];
                    $descripcion = $row[5];
                    
                    echo '<br><br><form class="login_form" action="modificar.php" method="POST" id="modificar_concierto" enctype="multipart/form-data">
                            <img src="'. $cartel. '" class="slides" alt="cartel"><br><br> 
                        Nombre del concierto <br> <input type="text" name="nombre_concierto_modificado" value="'.$nombre.'"> <br><br>
                           Fecha <br> <input type="date" name="fecha_concierto_modificado" value="'.$fecha.'"> <br><br>
                           Cartel  <input type="file" name="cartel_concierto_modificado" id="cartel_concierto_modificado"> <br><br>
                            <input type="hidden" name="nombre_anterior" value="'.$nombre.'">
                            Hora <br> <input type="text" name="hora_concierto_modificado" value="'.$hora.'"> <br><br>
                            Lugar <br> <input type="text" name="lugar_concierto_modificado" value="'.$lugar.'"> <br><br>
                            Descripcion <br><textarea rows="10" cols="50" name="descripcion_concierto_modificada" form="modificar_concierto">' . $descripcion .'</textarea> <br> 
                           <input type="submit" value="Modificar">
                        </form>
                    ';

                    echo '<form class="login_form delete" action="modificar.php" method="POST" enctype="multipart/form-data">
                            <input type="hidden" name="nombre_anterior" value="'.$nombre.'"> 
                            <input type="hidden" name="borrarConcierto" value="borrarConcierto">
                            <input type="submit" value="Borrar">
                        </form>
                    ';
            }

            
            if(isset($_POST['nombre_concierto_modificado']) &&
                isset($_POST['fecha_concierto_modificado']) &&
                isset($_POST['lugar_concierto_modificado']) &&
                isset($_POST['hora_concierto_modificado']) &&
                isset($_POST['descripcion_concierto_modificada']) 
            
            ){
                
                if(preg_match('/\d/', $_POST['nombre_concierto_modificado'])){
                    header("Location: gestion.php");
                }
                
                    $nombre_anterior = $_POST['nombre_anterior'];
                    
                    
                    
                    $target_dir = "imagenes_subidas/conciertos/";
                    $target_file = $target_dir . basename($_FILES["cartel_concierto_modificado"]["name"]);
                

                    if (file_exists($target_file)) {
                       
                        
                        if (move_uploaded_file($_FILES["cartel_concierto_modificado"]["tmp_name"], $target_file)) {


                            $sql = "UPDATE `conciertos` SET `cartel` = '$target_file' WHERE `conciertos`.`nombre` = '$nombre_anterior'";
                            $mysqli->query($sql) or die($mysqli->error);

                        } 
                    }
                    

                    $nuevo_nombre = $_POST['nombre_concierto_modificado'];
                    $nueva_fecha = $_POST['fecha_concierto_modificado'];
                    $nueva_hora = $_POST['hora_concierto_modificado'];
                    $nuevo_lugar = $_POST['lugar_concierto_modificado'];
                    $nueva_descripcion = $_POST['descripcion_concierto_modificada'];
                    
                    $sql = "UPDATE `conciertos` SET `nombre` = '$nuevo_nombre', `fecha` = '$nueva_fecha', `hora` = '$nueva_hora', `lugar` = '$nuevo_lugar', `descripcion` = '$nueva_descripcion' WHERE `conciertos`.`nombre` = '$nombre_anterior'";
                    $mysqli->query($sql) or die($mysqli->error);
                    
                    header("Location: gestion.php");
            
            }

            if(isset($_POST['borrarConcierto'])){
                $nombre_anterior = $_POST['nombre_anterior'];
                
                $sql = "SELECT * FROM `conciertos` WHERE nombre = '$nombre_anterior';";
            
                $result =  $mysqli->query($sql) or die($mysqli->error);
                $row = $result->fetch_row(); 
                $cartel = $row[0];
               
                unlink($cartel);

                $sql = "DELETE FROM `conciertos` WHERE `conciertos`.`nombre` = '$nombre_anterior';";
                $mysqli->query($sql) or die($mysqli->error);
                    
                header("Location: gestion.php");
            
            }

            // COMPONENTES

            if(isset($_POST['nombre_componente_mod']) &&
                isset($_POST['fecha_nacimiento_mod']) &&
                isset($_POST['bio_componente_mod'])
                ){


                    $nombre = $_POST['nombre_componente_mod'];
                    
                    $sql = "SELECT * FROM `componentes` WHERE nombre = '$nombre';";
                    
                    $result =  $mysqli->query($sql) or die($mysqli->error);
                    
                    $row = $result->fetch_row();

                    $fecha = $row[1];
                    $foto = $row[2];
                    $descripcion = $row[3];
                    
                    echo '<br><br><form class="login_form" action="modificar.php" method="POST" id="modificar_componente" enctype="multipart/form-data">
                            <img src="'. $foto. '" class="slides" alt="foto"><br><br> 
                        Nombre del componente <br> <input type="text" name="nombre_componente_modificado" value="'.$nombre.'"> <br><br>
                           Fecha de nacimiento <br> <input type="date" name="fecha_componente_modificado" value="'.$fecha.'"> <br><br>
                           Foto del componente  <input type="file" name="foto_componente_modificado" id="foto_componente_modificado"> <br><br>
                            <input type="hidden" name="nombre_anterior" value="'.$nombre.'">
                            Reseña biográfica <br><textarea rows="10" cols="50" name="bio_componente_modificada" form="modificar_componente">' . $descripcion .'</textarea> <br> 
                           <input type="submit" value="Modificar">
                        </form>
                    ';

                    echo '<form class="login_form delete" action="modificar.php" method="POST" enctype="multipart/form-data">
                            <input type="hidden" name="nombre_anterior" value="'.$nombre.'"> 
                            <input type="hidden" name="borrarComponente" value="borrarComponente">
                            <input type="submit" value="Borrar">
                        </form>
                    ';
            }

            
            if(isset($_POST['nombre_componente_modificado']) &&
                isset($_POST['fecha_componente_modificado']) &&
                isset($_POST['bio_componente_modificada']) 
            ){
                
                if(preg_match('/\d/', $_POST['nombre_componente_modificado'])){
                    header("Location: gestion.php");
                }
                
                    $nombre_anterior = $_POST['nombre_anterior'];
                    
                    
                    
                    $target_dir = "imagenes_subidas/componentes/";
                    $target_file = $target_dir . basename($_FILES["foto_componente_modificado"]["name"]);
                

                    if (file_exists($target_file)) {
                       
                        
                        if (move_uploaded_file($_FILES["foto_componente_modificado"]["tmp_name"], $target_file)) {


                            $sql = "UPDATE `componentes` SET `foto` = '$target_file' WHERE `componentes`.`nombre` = '$nombre_anterior'";
                            $mysqli->query($sql) or die($mysqli->error);

                        } 
                    }
                    

                    $nuevo_nombre = $_POST['nombre_componente_modificado'];
                    $nueva_fecha = $_POST['fecha_componente_modificado'];
                    $nueva_descripcion = $_POST['bio_componente_modificada'];
                    
                    $sql = "UPDATE `componentes` SET `nombre` = '$nuevo_nombre', `nacimiento` = '$nueva_fecha', `bio_componente` = '$nueva_descripcion' WHERE `componentes`.`nombre` = '$nombre_anterior'";
                    $mysqli->query($sql) or die($mysqli->error);
                    
                    header("Location: gestion.php");
             
            }

            if(isset($_POST['borrarComponente'])){
                $nombre_anterior = $_POST['nombre_anterior'];
                
                $sql = "SELECT * FROM `componentes` WHERE nombre = '$nombre_anterior';";
            
                $result =  $mysqli->query($sql) or die($mysqli->error);
                $row = $result->fetch_row(); 
                $foto = $row[2];
               
                unlink($foto);

                $sql = "DELETE FROM `componentes` WHERE `componentes`.`nombre` = '$nombre_anterior';";
                $mysqli->query($sql) or die($mysqli->error);
                    
                header("Location: gestion.php");
            
            }


            // BIOGRAFÍA

            if(isset($_POST['biografia_mod']) 
                ){


                    $id = $mysqli->real_escape_string($_POST['id_acon_mod']);
                    
                    $sql = "SELECT * FROM `biografia` WHERE id = '$id';";
                    
                    $result =  $mysqli->query($sql) or die($mysqli->error);
                    
                    $row = $result->fetch_row();

                    $fecha = $row[1];
                    $texto = $row[2];
                    
                    echo '<br><br><form class="login_form" action="modificar.php" method="POST" id="modificar_bio" enctype="multipart/form-data">
                           Fecha <br> <input type="text" name="fecha_bio_modificado" value="'.$fecha.'"> <br><br>
                            <input type="hidden" name="id_anterior" value="'.$id.'">
                            Biografía <br><textarea rows="10" cols="50" name="bio_modificada" form="modificar_bio">' . $texto .'</textarea> <br> 
                           <input type="submit" value="Modificar">
                        </form>
                    ';

                    echo '<form class="login_form delete" action="modificar.php" method="POST" enctype="multipart/form-data">
                            <input type="hidden" name="id_anterior" value="'.$id.'"> 
                            <input type="hidden" name="borrarBio" value="borrarBio">
                            <input type="submit" value="Borrar">
                        </form>
                    ';
            }

            
            if(isset($_POST['bio_modificada'])
            ){
                
                
                    $id_anterior = $_POST['id_anterior'];
                    
                    $nuevo_texto = $mysqli->real_escape_string($_POST['bio_modificada']);
                    
                    if(isset($_POST['fecha_bio_modificado'])){
                        $nueva_fecha = $mysqli->real_escape_string($_POST['fecha_bio_modificado']);
                        $sql = "UPDATE `biografia` SET `fecha` = '$nueva_fecha', `texto` = '$nuevo_texto' WHERE `biografia`.`id` = '$id_anterior'";
                    }else{
                        $sql = "UPDATE `biografia` SET  `texto` = '$nuevo_texto' WHERE `biografia`.`id` = '$id_anterior'";
                    }

                    
                    $sql = "UPDATE `biografia` SET `fecha` = '$nueva_fecha', `texto` = '$nuevo_texto' WHERE `biografia`.`id` = '$id_anterior'";
                    $mysqli->query($sql) or die($mysqli->error);
                    
                    header("Location: gestion.php");
             
            }

            if(isset($_POST['borrarBio'])){
                $id_anterior = $_POST['id_anterior'];
                

                $sql = "DELETE FROM `biografia` WHERE `biografia`.`id` = '$id_anterior';";
                $mysqli->query($sql) or die($mysqli->error);
                    
                header("Location: gestion.php");
            
            }

            // USUARIOS

            if(isset($_POST['nombre_pers_mod']) &&
                isset($_POST['apellidos_pers_mod']) &&
                isset($_POST['telefono_pers_mod']) &&
                isset($_POST['email_pers_mod']) 
                ){

                    $tipo = $_POST['tipo'];

                    $email = $mysqli->real_escape_string($_POST['email_pers_mod']);

                    if($tipo == 'admin'){
                        $sql = "SELECT * FROM `admins` WHERE email = '$email';";
                        $tipo_per = '<input type="hidden" name="tipo" value="admin">';
                    }else if($tipo == 'gestor'){
                        $sql = "SELECT * FROM `gestores` WHERE email = '$email';";
                        $tipo_per = '<input type="hidden" name="tipo" value="gestor">';
                    }
                
                    
                    $result =  $mysqli->query($sql) or die($mysqli->error);
                    
                    $row = $result->fetch_row();
                    
                    $nombre = $row[0];
                    $apellidos = $row[1];
                    $telefono = $row[2];
                    
                    
                    echo '<br><br><form class="login_form" action="modificar.php" method="POST" id="modificar_pers" enctype="multipart/form-data">
                           Nombre <br> <input type="text" name="nombre_per_modificado" value="'.$nombre.'"> <br><br>
                            <input type="hidden" name="email_per_anterior" value="'.$email.'">
                            Apellidos <br> <input type="text" name="apellidos_per_modificado" value="'.$apellidos.'"> <br><br>
                            '.$tipo_per.'
                            Telefono <br> <input type="text" name="telf_per_modificado" value="'.$telefono.'"> <br><br>
                            Email <br> <input type="text" name="email_per_modificado" value="'.$email.'"> <br><br>
                            Nueva contraseña <br> <input type="password" name="nueva_pass"> <br><br>
                           <input type="submit" value="Modificar">
                        </form>
                    ';

                    echo '<form class="login_form delete" action="modificar.php" method="POST" enctype="multipart/form-data">
                            <input type="hidden" name="email_per_anterior" value="'.$email.'"> 
                            <input type="hidden" name="borrarPer" value="borrarPer">
                            '.$tipo_per.'
                            <input type="submit" value="Borrar">
                        </form>
                    ';
            }

            
            if(isset($_POST['nombre_per_modificado']) &&
                isset($_POST['apellidos_per_modificado']) &&
                isset($_POST['telf_per_modificado']) &&
                isset($_POST['email_per_modificado']) 
                ){
                
                
                    $email_anterior = $_POST['email_per_anterior'];

                    $nuevo_nombre =  $mysqli->real_escape_string($_POST['nombre_per_modificado']);
                    $nuevo_apellidos =  $mysqli->real_escape_string($_POST['apellidos_per_modificado']);
                    $nuevo_telf =  $mysqli->real_escape_string($_POST['telf_per_modificado']);
                    $nuevo_email =  $mysqli->real_escape_string($_POST['email_per_modificado']);

                    if(isset($_POST['tipo'])){

                        if($_POST['tipo'] == 'admin'){
                            if(isset($_POST['nueva_pass']) && $_POST['nueva_pass'] != ""){
                                $pass = base64_encode($_POST['nueva_pass']);
                                $sql_prev = "UPDATE `admins` SET `clave_cifrada` = '$pass' WHERE `admins`.`email` = '$email_anterior'";
                                $sql_prev2 = "UPDATE `usuarios` SET `clave_cifrada` = '$pass' WHERE `usuarios`.`email` = '$email_anterior'";
                                $mysqli->query($sql_prev) or die($mysqli->error);
                                $mysqli->query($sql_prev2) or die($mysqli->error);
                            }
                            $sql = "UPDATE `admins` SET `nombre` = '$nuevo_nombre', `apellidos` = '$nuevo_apellidos', `telefono` = '$nuevo_telf', `email` = '$nuevo_email' WHERE `admins`.`email` = '$email_anterior'";
                            $sql2 = "UPDATE `usuarios` SET `email` = '$nuevo_email' WHERE `usuarios`.`email` = '$email_anterior'";
                        }else if($_POST['tipo'] == 'gestor'){
                            if(isset($_POST['nueva_pass']) && $_POST['nueva_pass'] != ""){
                                $pass = base64_encode($_POST['nueva_pass']);
                                $sql_prev = "UPDATE `gestores` SET `clave_cifrada` = '$pass' WHERE `gestores`.`email` = '$email_anterior'";
                                $sql_prev2 = "UPDATE `usuarios` SET `clave_cifrada` = '$pass' WHERE `usuarios`.`email` = '$email_anterior'";
                                $mysqli->query($sql_prev2) or die($mysqli->error);
                                $mysqli->query($sql_prev) or die($mysqli->error);
                            }
                            $sql = "UPDATE `gestores` SET `nombre` = '$nuevo_nombre', `apellidos` = '$nuevo_apellidos', `telefono` = '$nuevo_telf', `email` = '$nuevo_email' WHERE `gestores`.`email` = '$email_anterior'";
                            $sql2 = "UPDATE `usuarios` SET `email` = '$nuevo_email' WHERE `usuarios`.`email` = '$email_anterior'";
                        }
                    }
                
                    $mysqli->query($sql) or die($mysqli->error);
                    $mysqli->query($sql2) or die($mysqli->error);
                    
                    header("Location: gestion.php");
             
            }

            if(isset($_POST['borrarPer'])){
                $email_anterior = $_POST['email_per_anterior'];
                $tipo = $_POST['tipo'];
                
                if($tipo == 'admin'){
                    $sql = "DELETE FROM `admins` WHERE `admins`.`email` = '$email_anterior';";
                }else if($tipo == 'gestor'){
                    $sql = "DELETE FROM `gestores` WHERE `gestores`.`email` = '$email_anterior';";
                }
                $sql2 = "DELETE FROM `usuarios` WHERE `usuarios`.`email` = '$email_anterior';";

                $mysqli->query($sql) or die($mysqli->error);
                $mysqli->query($sql2) or die($mysqli->error);
                    
                header("Location: gestion.php");
            
            }



            }
                    
                        
                ?>
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
