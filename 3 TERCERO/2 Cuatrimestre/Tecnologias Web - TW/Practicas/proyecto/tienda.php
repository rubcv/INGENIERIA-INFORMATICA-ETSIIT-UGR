
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
						<a href="index.php"> <p class="contenido" > Volver a inicio </p> </a> <br>	
						
						<?php 
						require_once 'database/conexion.php';

						session_start();
						
						if(isset($_SESSION['nombre'])){ // Si somos usuario registrado
							echo '<p id="sesion_header"> <strong> Saludos ' . $_SESSION['nombre'] . ' - sesión iniciada como ' . $_SESSION['tipo'] . '<a href="database/logout.php"> (click aqui para cerrar sesión) </a> </strong></p> <br>	';
							echo '<a href="gestion.php"> <p class="contenido">  &#8614;<strong> Ir al panel de gestión </strong></p> </a> <br>';	
						}else{ // Si no lo somos
							echo '<a href="login.php"> <p class="contenido"> <strong> Iniciar sesión - Registrarme </strong></p> </a> <br>';	
						}
						?>
					</nav>
				</section>
			</section>			
			<!-- ---------------------------------------------------------- -->
			
			<section class="titulo_info">
					<h2> Tienda </h2>
				</section>

				<?php

					// Validamos los campos en PHP
					function validoCampos(){
						if(preg_match('/\d/', $_POST['nombre']) || preg_match('/\d/', $_POST['apellidos'])){
							return false;
						}

						if(strlen($_POST['telefono']) != 9){
							return false;
						}

						$caduca = new DateTime($_POST['caducidad']);
						$ahora = new DateTime();    
						
						if($caduca < $ahora){
							return false;
						}

						if(!preg_match("/(^[a-zA-Z][\w\_\\-])+[\w]+[@][a-z]+(\.[a-z]+)*\.[a-z]{2,3}/", $_POST['email'])){
							return false;
						}            
						

						return true;
					}

					require_once 'database/conexion.php';


						if(isset($_POST['nombre']) &&
							isset($_POST['apellidos']) &&
							isset($_POST['email']) &&
							isset($_POST['telefono']) &&
							isset($_POST['pago']) &&
							isset($_POST['caducidad']) &&
							isset($_POST['codtarjeta']) 

						){ // Procesar compra

							if(validoCampos()){
								
								$correo_cliente = $mysqli->real_escape_string($_POST['email']);
								$fecha_pedido = date("y-m-d");
								$nombre_producto = "||";

								for ($i=0; $i < sizeof($_POST['articulos']) ; $i++) { 
									
									$nombre_producto .= $_POST['articulos'][$i] . " || "; // Separamos los productos adquiridos con ||
								}

								$nombre_producto = $mysqli->real_escape_string($nombre_producto);

								$estado = "pendiente"; // Por defecto su estado es pendiente
								$null = "NULL";

								$sql = "INSERT INTO `pedidos` (correo_cliente, fecha_pedido, fecha_gest, nombre_gest, apellidos_gest, estado, email_enviado, nombre_producto, id) VALUES ('$correo_cliente', '$fecha_pedido', '$null', '$null', '$null', '$estado', '$null', '$nombre_producto', '$null');";
								guardarLogs($sql); // Guardamos registro de la compra en los logs
								$mysqli->query($sql) or die($mysqli->error);
								
								echo '<script>
									alert("Compra realizada con éxito");
									</script>
									';
									//header("Location: tienda.php");
							}else{
								header("Location: tienda.php?error=true");
							}
						}

						if(isset($_GET['error'])){ // Si ha habido error en la compra
							echo '<script>
								alert("Error en la compra, revisa los campos");
								</script>
							';
						}



						$sql = "SELECT * FROM `articulos`"; // Mostramos todos los articulos

						$result =  $mysqli->query($sql) or die($mysqli->error);

						$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

						if(!empty($campos)){ // Formulario con todos los articulos para seleccionar con un checkbox
							
							echo '<form action="tienda.php" class="giras_scope" method="POST" onsubmit="return validate(this);">';	
							
							for ($i=0; $i < sizeof($campos) ; $i++) {
								echo '<h4 id="nombre_articulo">'.$campos[$i]['nombre'] . '</h4>';
								echo '<img class="slides_tienda" src="' .$campos[$i]['foto'] .'" alt="articulo">' ;
								echo '<section id="comprar_articulo" >';
								echo '<input type="checkbox" name="articulos[]" value="'. $campos[$i]['nombre'] .'"> Comprar '.  $campos[$i]['nombre'] ;
								echo '<span id="comprar_inner1"> ' . $campos[$i]['precio'] . ' &euro;</span>';
								echo '</section>';
							}
						}

				?>
				
					<section class="login_form"> <!-- Formulario con los datos del usuario -->
						<br><br>
						Nombre: <br>
						<input type="text" name="nombre">
						<br><br>
						Apellidos: <br>
						<input type="text" name="apellidos">
						<br><br>
						Correo: <br>
						<input type="email" name="email">
						<br><br>
						Teléfono: <br>
						<input type="number" name="telefono"><br><br>
						Dirección: <br>
						<input type="text" name="direccion"> 
						<h4> Datos de pago: </h4>
						<input type="radio" name="pago" value="tarjeta"> Tarjeta 
						<input type="radio" name="pago" value="reembolso"> Contra-reembolso
						<br><br>Número de tarjeta: <br>
						<input type="text" name="tarjeta">
						<br><br>
						Fecha de caducidad: <br>
						<input type="date" name="caducidad"><br><br>
						Código de seguridad: <br>
						<input type="number" name="codtarjeta"> <br><br>
						<br><br>
						<input type="submit" id="buyBtt" value="Comprar"> <br>
					</section>
				</form>
			</section>
			<!-- ---------------------------------------------------------- -->
