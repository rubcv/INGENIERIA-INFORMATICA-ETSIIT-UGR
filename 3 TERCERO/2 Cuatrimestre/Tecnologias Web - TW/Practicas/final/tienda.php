
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

				// Validamos los campos con javascript

				function validate(form){
					var result = confirm("Confirmar esta compra?");

					if(!result){
						return false;
					}else{

						var nombre = $("input[name=nombre]").val();
						var apellidos = $("input[name=apellidos]").val();
						var email = $("input[name=email]").val();
						var telefono = $("input[name=telefono]").val();
						var direccion = $("input[name=direccion]").val();
						var pago = $("input[name=pago]").val();
						var tarjeta = $("input[name=tarjeta]").val();
						var caducidad = $("input[name=caducidad]").val();
						var codtarjeta = $("input[name=codtarjeta]").val();

						if (!/^[a-zA-Z]+$/.test(nombre)){
							alert("El nombre " + nombre + " contiene caracteres no válidos");
							return false;
						}

						if (!/^[a-zA-Z]+$/.test(apellidos)){
							alert("El nombre " + apellidos + " contiene caracteres no válidos");
							return false;
						}
						
						var re = /\S+@\S+\.\S+/;
						if(!re.test(email)){
							alert("Email no válido");
							return false;
						}
						
						if (/^[a-zA-Z]+$/.test(telefono) || telefono.length != 9){
							alert("El teléfono no es válido");
							return false;
						}


						var d1 = new Date();
						var d2 = new Date(caducidad);
						if(d1.getTime() > d2.getTime()){
							alert("Fecha de caducidad no válida");
							return false;
						}
						
						if (/^[a-zA-Z]+$/.test(codtarjeta)){
							alert("El código de la tarjeta no es válido");
							return false;
						}

					}
				}

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
			
			<section id="fondo-navegacion">
				<section id="navegacion"> 
						<a href="index.php"> <p class="contenido" > Volver a inicio </p> </a> <br>	
						
						<?php 
						require_once 'database/conexion.php';

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
			
			<section class="titulo_info">
					<h2> Tienda </h2>
				</section>

				<?php

					// Volvemos a validar los campos ahora en php
					function validoCampos(){
						if(preg_match('/\d/', $_POST['nombre']) || preg_match('/\d/', $_POST['apellidos'])){
							return false;
						}

						if(strlen($_POST['telefono']) != 9){
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
									
									$nombre_producto .= $_POST['articulos'][$i] . " || ";
								}

								$nombre_producto = $mysqli->real_escape_string($nombre_producto);

								$estado = "pendiente";
								$null = "NULL";

								$sql = "INSERT INTO `pedidos` (correo_cliente, fecha_pedido, fecha_gest, nombre_gest, apellidos_gest, estado, email_enviado, nombre_producto, id) VALUES ('$correo_cliente', '$fecha_pedido', '$null', '$null', '$null', '$estado', '$null', '$nombre_producto', '$null');";
								
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

						if(isset($_GET['error'])){
							echo '<script>
								alert("Error en la compra, revisa los campos");
								</script>
							';
						}



						$sql = "SELECT * FROM `articulos`";

						$result =  $mysqli->query($sql) or die($mysqli->error);

						$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

						if(!empty($campos)){
							
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
				
					<section class="login_form">
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
