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
					$(".contenido").click(function(){
						var url = $(this).attr('id'); 
						
						$.ajax({
								type : "POST",
								url  : url,
								success: function(result) {
									
									$("#imprimirAqui").html(result);

									$(".buyBtt").click(function(){
										var url = 'database/comprar.php';
										var data = $(this).attr('class').split(' ')[1]; 
										var mostrar = '.imprimir' + data ;
										
										$.ajax({
												type : "POST",
												url  : url,
												data :  {'disco': data}, 
												success: function(res) {
													
													$(mostrar).html(res);

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
						<p class="contenido" id="principal.php"> Inicio  </p> <br>
					 	<p class="contenido" id="biografia.php"> Biografía  </p><br>					
						<p class="contenido" id="discografia.php"> Discografía </p><br>		
						 <a href="tienda.php"> <p class="contenido" > Tienda </p> </a> <br>	
						
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
			
		<section id="imprimirAqui">
			

			<!-- ---------------------------------------------------------- -->
			
			<section class="titulo_info">
				<h2> Synopsis </h2>
			</section>
			<section id="sinopsis">
					<?php
						 $sql = "SELECT * FROM `componentes`";

						 $result =  $mysqli->query($sql) or die($mysqli->error);
							 
						 $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

						 if(!empty($campos)){
							
							for ($i=0; $i < sizeof($campos) ; $i++) {
								echo '<h4>'.$campos[$i]['nombre'] . '</h4>';
								echo $campos[$i]['bio_componente'];
							}
						}


					?>
				<h4> Algunos éxitos </h4>
					
						<?php
								$sql = "SELECT * FROM `discos`";

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
						  $sql = "SELECT * FROM `conciertos`";

						  $result =  $mysqli->query($sql) or die($mysqli->error);
							  
						  $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
				  
						  if(!empty($campos)){							 
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
					

					  $sql = "SELECT * FROM `articulos`";

					  $result =  $mysqli->query($sql) or die($mysqli->error);
						  
					  $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

					  
			?>

			<script>
					var nombre = new Array();
					var precio = new Array();

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
							for ($i=0; $i < sizeof($campos); $i++) { 
								echo '<img class="slides" src="'. $campos[$i]['foto'] .'" alt="imagen">';
							}
						?>
						
					</section>
					<?php
						if(!empty($campos)){
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
						var x = document.getElementsByClassName("slides");
						for (i = 0; i < x.length; i++) {
						x[i].style.display = "none";  
						}
						myIndex++;
						if (myIndex > x.length) {myIndex = 1}    
						x[myIndex-1].style.display = "block";  
						
						
						setTimeout(carousel, 1000); 
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
			 <a href=""> Mapa del sitio </a> 
		</nav>
	</footer>


			

	</body>
</html>
