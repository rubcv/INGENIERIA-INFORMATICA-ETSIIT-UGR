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
                function getCookie(name) {
                    var value = "; " + document.cookie;
                    var parts = value.split("; " + name + "=");
                    if (parts.length == 2) return parts.pop().split(";").shift();
                }
                $(document).ready(function(){
                        if ((document.cookie.indexOf("email=") >= 0) && (document.cookie.indexOf("pass=") >= 0)){
                            $("#email_c").val(getCookie('email').replace('%40','@'));
                            $("#pass_c").val(getCookie('pass'));
                        }

                    });

				$(document).ready(function(){
					$("#iniciar").click(function(){

                        var result = confirm("Deseas guardar este login?");

                        if(result){
                           var str =  $('#login_s').serialize();
                           var campos = str.split("&");
                            
                            var email = decodeURI(campos[0].split("=")[1]);
                            var pass = campos[1].split("=")[1];
                            
                           
                            document.cookie = "email="+email;
                            document.cookie = "pass="+pass;
                        }

                    });
				});
            </script>
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
            

            <?php
                    require_once 'database/conexion.php';
                    
                    session_start();

                    function validoLogin($email, $pass, $mysqli){
                        
                        if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
                            return false;
                        }else{
                            $sql = "SELECT clave_cifrada FROM `usuarios` WHERE email = '$email';";
                            $result =  $mysqli->query($sql) or die($mysqli->error);
                                
                            $row = $result->fetch_row();
            
                            $pass_guardada = $row[0];
            
                           $pass = base64_encode($pass);
                           
                            if($pass_guardada != $pass){
                                return false;
                            }
                        }
            
                        return true;
                    }



                    if(isset($_POST['email']) && isset($_POST['password'])){
                        
                        if(validoLogin($_POST['email'], $_POST['password'], $mysqli)){
                    

                            $email = $mysqli->real_escape_string($_POST['email']);
                            $pass =  $mysqli->real_escape_string($_POST['password']); 
        
                            $pass =  base64_encode($pass);
        
                            $sql = "SELECT * FROM `usuarios` WHERE email = '$email' AND clave_cifrada = '$pass';";
                    
                            $result =  $mysqli->query($sql) or die($mysqli->error);
                            
                            $row = $result->fetch_row();
                        
                           $tipo = $row[2];

                           if($tipo == "admin"){
                                $sql = "SELECT * FROM `admins` WHERE email = '$email' AND clave_cifrada = '$pass';";
                           }else if($tipo == "gestor"){
                                $sql = "SELECT * FROM `gestores` WHERE email = '$email' AND clave_cifrada = '$pass';";
                           }

                           $result =  $mysqli->query($sql) or die($mysqli->error);
                            
                           $row = $result->fetch_row();
                           
                           $_SESSION['nombre'] = $row[0];
                           $_SESSION['apellidos'] = $row[1];
                           $_SESSION['telefono'] = $row[2];
                           $_SESSION['email'] = $row[3];
                           $_SESSION['tipo'] = $tipo;
                          
                           header("Location: index.php");
                           
                        }else{
                            header("Location: login.php?login=false");
                        }
                    }

                    if(isset($_POST['nombre']) && 
                       isset($_POST['apellidos']) && 
                       isset($_POST['telefono']) &&
                       isset($_POST['email_r'])&&
                       isset($_POST['password_r']) &&
                       isset($_POST['tipo'])){

                        $error = false;

                        if(!filter_var($_POST['email_r'], FILTER_VALIDATE_EMAIL)){
                           $error = true;
                       }

                       if(preg_match('/\d/', $_POST['nombre']) || preg_match('/\d/', $_POST['apellidos'])){
                           $error = true;
                       }

                       if(!preg_match("/[0-9]{9}/", $_POST['telefono'])) {
                            $error = true;
                      }

                      if($_POST['tipo'] != 'admin' && $_POST['tipo'] != 'gestor'){
                         $error = true;
                       }

                      if($error){
                          header("Location: login.php?result=false");
                      }


                        $nombre =  $mysqli->real_escape_string($_POST['nombre']); 
                        $apellidos =  $mysqli->real_escape_string($_POST['apellidos']); 
                        $telefono =  $mysqli->real_escape_string($_POST['telefono']); 
                        $email = $mysqli->real_escape_string($_POST['email_r']);
                        $pass =  base64_encode($_POST['password_r']);
                        $tipo = $mysqli->real_escape_string($_POST['tipo']);
                      
                       
                        // Comprobamos que no exista ya

                        $sql = "SELECT * FROM `usuarios` WHERE email = '$email'";
                       

                        $result =  $mysqli->query($sql) or die($mysqli->error);
                            
                        $row = $result->fetch_row();

                        if(!empty($row)){
                            header("Location: login.php?result=false");
                        }


                        if($_POST['tipo'] == 'admin'){
                        
                            $sql  = "INSERT INTO `admins` (nombre, apellidos, telefono, email, clave_cifrada) VALUES ('$nombre', '$apellidos', '$telefono', '$email', '$pass');";
                        }else if($_POST['tipo'] == 'gestor'){
                            $sql  = "INSERT INTO `gestores` (nombre, apellidos, telefono, email, clave_cifrada) VALUES ('$nombre', '$apellidos', '$telefono', '$email', '$pass');";
                        }

                        $mysqli->query($sql) or die($mysqli->error);

                        $sql = "INSERT INTO `usuarios`(email, clave_cifrada, tipo) VALUES ( '$email', '$pass', '$tipo');";
                        
                        $mysqli->query($sql) or die($mysqli->error);

                        header("Location: login.php?result=true");
                    }
                       
                    
                
                    if(isset($_GET['result']) && $_GET['result'] == 'true'){
                            echo '<script> alert("Usuario creado correctamente"); </script>';
                    }else if(isset($_GET['result']) && $_GET['result'] == 'false'){
                            echo '<script> alert("Fallo al crear el usuario, datos incorrectos o usuario ya existente"); </script>';
                    }

                    if(isset($_GET['login']) && $_GET['login'] == 'false'){
                        echo '<script> alert("Fallo al iniciar sesión, datos incorrectos o el usuario no existe"); </script>';
                    }
                      
            ?>
            
                            
			<section id="fondo-navegacion">
				<section id="navegacion"> 
                    <p class="contenido2"> Bienvenido a Snoop Dogg Official Site </p> <br>
						<a href="index.php">  <p class="contenido">&#8614; Volver a Inicio  </p> </a>  <br>
					</nav>
				</section>
			</section>		
			<!-- ---------------------------------------------------------- -->
            <form class="login_form" id="login_s" action="login.php" method="POST">
			<h1> Login </h1>
               Email <br><input type="email" id="email_c" name="email"> <br><br>
                Contraseña <br> <input type="password" id="pass_c" name="password"> <br><br>
                <input type="submit" id="iniciar" value="Iniciar sesión">
            </form>

            <form class="login_form" action="login.php" method="POST">
            <h1> Registrarme </h1>
                Nombre <br> <input type="text" name="nombre"> <br><br>
                Apellidos <br> <input type="text" name="apellidos"> <br><br>
                Telefono <br> <input type="tel" name="telefono"> <br><br>
               Email <br><input type="email" name="email_r"> <br><br>
                Contraseña <br> <input type="password" name="password_r"> <br><br>
                Soy admin <input type="radio" name="tipo" value="admin"> 
                Soy gestor <input type="radio" name="tipo" value="gestor"> <br><br>
                <input type="submit" value="Registrarme">
            </form>
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
