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
	
			<script>   
			
				// BUSQUEDA
				$(document).ready(function(){
					$(".Btt").click(function(){ // Si el usuario pincha en buscar
						var url = $(this).attr('id'); //Se extrae el id que es la pagina de busqueda.php
						
						$.ajax({
								type : "POST",
								url  : url,

								success: function(result) { // Se le hace un post
									$('.Btt').css("display" , "none");
									$("#busquedaAvanzada").html(result); // Aqui se muestran los campos (texto y tipo)

									$("#campoBus").click(function(){ // Click sobre tipo (disco/conc.)
										var data = $('#campoBus').val(); //Se extrae el valor y se le hace post a busqueda.php
										
										$.ajax({
												type : "POST",
												url  : url,
												data : {'campo' : data}, //data es disco o concierto
												success: function(result) {
													
													$("#busquedaAvanzada2").html(result);//Se imprime el resultado, que son input fecha disco o lugar conierto
													
													$(".BusquedaBtt").click(function(){ // Se hace click sobre busqueda
														var nombre = $('#nombre_bus').val(); //Se extraen los datos del formulario
														var lugar = $('#lugarconc').val();
														var ini = $('#fecha_ini').val();
														var fin = $('#fecha_fin').val();

														$.ajax({
																type : "POST",
																url  : url, // Nuevo post a busqueda.php con todos los datos
																data : {'buscar' : nombre,
																		'lugar' : lugar,
																		'fecha_ini' : ini,
																		'fecha_fin' : fin},
																success: function(result) {
																	
																	$("#busquedaAvanzada3").html(result); //Se imprime el resultado de la busqueda


																}       
														});
													});

												}       
										});
									});

								}       
						});
					});
				});

				// MENU
				$(document).ready(function(){ // Para todos los elementos del menú (Clase contenido)
					$(".contenido").click(function(){
						var url = $(this).attr('id'); // El atributo id es el que contiene el php que nos muestra la información
						
						$.ajax({ // Hacemos un post a ese id
								type : "POST",
								url  : url,
								success: function(result) {
									
									$("#imprimirAqui").html(result); // En el section con id="imprimmirAqui" lo mostramos

									$(".buyBtt").click(function(){ // Se hace cuando el anterior carga la discografia.php
										var url = 'database/comprar.php';
										var data = $(this).attr('class').split(' ')[1]; 
										var mostrar = '.imprimir' + data ; // Imprimimos el formulario de compra en
										//el section con clase="imprimir" + data (nombre del disco) (ver discografia.php)
										$.ajax({
												type : "POST",
												url  : url,
												data :  {'disco': data}, //Peticion a comprar.php con el corresp. disco
												success: function(res) {
													
													$(mostrar).html(res); //Mostramos el resultado

												}       
										});
									});

								}       
						});
					});
				});

			</script>
	</head>
	<body>
	<?php
			session_start();
	?>
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
				<section id="navegacion"> <!-- Cada elemento del menu se carga con AJAX -->
						<p class="contenido" id="principal.php"> Inicio  </p> <br>
					 	<p class="contenido" id="biografia.php"> Biografía  </p><br>					
						<p class="contenido" id="discografia.php"> Discografía </p><br>	
						 <a href="tienda.php"> <p class="contenido" > Tienda </p> </a> <br><!-- tienda tiene su pag. a parte-->
								
						
						<?php 
						require_once 'database/conexion.php';

						$sql = "SELECT * FROM `usuarios`"; //Vemos el numero de usuarios
						
						$result =  $mysqli->query($sql) or die($mysqli->error);
			
						$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
			
						if(empty($campos)){ // Si esta vacio = no hay = aplicacion recien instalada
							header("Location: database/welcome.php"); // Vamos a la pag. de bienvenida
						}

						
						
						if(isset($_SESSION['nombre'])){ // Si es un usuario identificado
							echo '<p id="sesion_header"> <strong> Saludos ' . $_SESSION['nombre'] . ' - sesión iniciada como ' . $_SESSION['tipo'] . '<a href="database/logout.php"> (click aqui para cerrar sesión) </a> </strong></p> <br>	';
							echo '<a href="gestion.php"> <p class="contenido">  &#8614;<strong> Ir al panel de gestión </strong></p> </a> <br>';	
						}else{
							echo '<a href="login.php"> <p class="contenido"> <strong> Iniciar sesión - Registrarme </strong></p> </a> <br>';	
						}
						?>

						<!-- FORMULARIO DE BUSQUEDA -->
						<button type="button" class="Btt" id="database/buscar.php"> Buscar </button> <br><br>

						<section id="busquedaAvanzada"> <!--Aqui se muestra el primer formulario (nombre y tipo) -->
						</section>
						<section id="busquedaAvanzada2"> <!--Segun el tipo disco/concierto se muestran los campos aqui -->
						</section>
						<section id="busquedaAvanzada3"> <!-- Aqui se muestra el resultado de la busqueda -->
						</section>
					
				</section>
			</section>			
			
		<section id="imprimirAqui"> <!-- Aqui mostramos cada html resultado de traer con AJAX cada elem. del menu -->
			

			<!-- ---------------------------------------------------------- -->
			
			<!-- Por defecto mostramos principal.php para que la pag. no esté vacia hasta que el usuario pulse en el menu -->

			<section class="titulo_info">
				<h2> Synopsis </h2>
			</section>
			<section id="sinopsis">
					<?php
						 $sql = "SELECT * FROM `componentes`"; // Extraemos todos los componentes

						 $result =  $mysqli->query($sql) or die($mysqli->error);
							 
						 $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

						 if(!empty($campos)){
							
							for ($i=0; $i < sizeof($campos) ; $i++) {
								echo '<h4>'.$campos[$i]['nombre'] . '</h4>'; // Mostramos su nombre
								echo $campos[$i]['bio_componente']; // Mostramos su reseña biografica
							}
						}


					?>
				<h4> Algunos éxitos </h4>
					
						<?php
								$sql = "SELECT * FROM `discos`"; // Mostramos nombre disco y fecha

								$result =  $mysqli->query($sql) or die($mysqli->error);
									
								$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

								if(!empty($campos)){
									echo '<ul>';
									for ($i=0; $i < sizeof($campos) ; $i++) {
										echo '<li>'.$campos[$i]['nombre'] ;
										echo '<strong> (' . $campos[$i]['year_s'] . ')</strong></li>' ;
									}
									echo '</ul>';
								}

						?>

			</section>
			
			<section class="titulo_info">
				<h2> Próximas giras </h2>
				<section id="giras">
					<?php
						  $sql = "SELECT * FROM `conciertos`"; // Extraemos los conciertos

						  $result =  $mysqli->query($sql) or die($mysqli->error);
							  
						  $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
				  
						  if(!empty($campos)){ // Mostramos cartel, nombre, lugar, fecha, descripcion, etc..							 
							  for ($i=0; $i < sizeof($campos) ; $i++) { 
								  $campos[$i]['fecha'] = date("d-m-Y", strtotime($campos[$i]['fecha']));
								  echo '<section class="giras_scope">';
								  echo '<img src="'. $campos[$i]['cartel'] . '" alt="cartel">';
								  echo '<section class="giras_desc">';
								  echo '<h4>'.$campos[$i]['nombre'].'</h4>';
								  echo '<p>El <span class="color_azul">'. $campos[$i]['fecha'] . '</span> en <span class="color_azul">' .$campos[$i]['lugar'] . '</span> a las <span class="color_azul">' . $campos[$i]['hora'] .'</span></p>';
								  echo '<p class ="descripcion_conc">'.$campos[$i]['descripcion'].'</p>';
								  echo '</section></section>';
						  
							  }
						  } 
					?>
				
				</section>
			</section>
			
			
			<?php 
					// Extraemos los articulos

					  $sql = "SELECT * FROM `articulos`";

					  $result =  $mysqli->query($sql) or die($mysqli->error);
						  
					  $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

					  
			?>

			<script>
					var nombre = new Array(); // Guardamos los articulos extraidos en array JS para 
					var precio = new Array(); // poder hacer el carousel

					<?php for ($i=0; $i < sizeof($campos) ; $i++) {  ?>
							nombre.push('<?php echo $campos[$i]['nombre']; ?>');
							precio.push('<?php echo $campos[$i]['precio']; ?>');
					<?php } ?>
			</script>

			<section class="titulo_info">
				<h2> Tienda </h2>
			</section>
					<section class="centrado">
						<?php
							for ($i=0; $i < sizeof($campos); $i++) { // Mostramos las fotos de los articulos
								echo '<img class="slides" src="'. $campos[$i]['foto'] .'" alt="imagen">';
							}
						?>
						
					</section>
					<?php
						if(!empty($campos)){ // Mostramos un mensaje de compra (importante: id's 'comprar_inner')
							echo '<section id="a_tienda">
									<h4>  <a href="tienda.php"> Comprar <span id="comprar_inner1"> </span> por tan sólo <span id="comprar_inner2"> </span> &euro; </a></h4>
								 </section>';

							echo '<section id="promo">
									<h4> ¡Aprovecha esta oportunidad! </h4>
								</section>
								';
						}
					?>
				<script>

					var myIndex = 0;
					carousel();

					function carousel() {
						var i;
						var x = document.getElementsByClassName("slides"); // x contiene todas las fotos de articulos
						for (i = 0; i < x.length; i++) {
						x[i].style.display = "none";  //Las ocultamos
						}
						myIndex++;
						if (myIndex > x.length) {myIndex = 1}    // Para cada llamada
						x[myIndex-1].style.display = "block";  
						
						
						setTimeout(carousel, 1000); //Establecemos que cambie cada 1s
						//Vamos cambiando el html de los elementos con estos id's, para que cambie de nombre y precio
						document.getElementById("comprar_inner1").innerHTML = nombre[myIndex % nombre.length] ;					
						document.getElementById("comprar_inner2").innerHTML = precio[myIndex % precio.length] ;
					}
				</script>
				</a>
			</section>
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
