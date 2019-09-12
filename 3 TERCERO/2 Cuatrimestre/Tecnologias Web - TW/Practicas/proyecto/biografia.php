
			<!-- ---------------------------------------------------------- -->
			<section id="biografia">
				<section class="titulo_info">
					<h2> Biografía </h2>
				</section>	

				<?php
					require_once 'database/conexion.php';
					
					$sql = "SELECT * FROM `componentes`"; // Cogemos las imagenes de los componentes

					$result =  $mysqli->query($sql) or die($mysqli->error);
						
					$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

					function custom_sort($a,$b) { // Función que ordena los hitos de antiguo a nuevo
						return $a['fecha']>$b['fecha'];
				   	};

					if(!empty($campos)){
					   
					   for ($i=0; $i < sizeof($campos) ; $i++) { // Mostramos las fotos de los componentes 
						   echo '<img class="foto_bio" src="' . $campos[$i]['foto'] .'">';
					   }
				   }

					$sql = "SELECT * FROM `biografia`"; //Recogemos los hitos

					$result =  $mysqli->query($sql) or die($mysqli->error);

					$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
					
					if(!empty($campos)){
						
						// Ordenamos por fecha
						usort($campos, "custom_sort");
						
					
						
						for ($i=0; $i < sizeof($campos) ; $i++) { // Mostramos los hitos
							echo '<h3>' . $campos[$i]['fecha'] .'</h3>';
							echo '<p>' . $campos[$i]['texto'] . '</p>';
						}
					}



				?>
					
				
			</section>
			
			<!-- ---------------------------------------------------------- -->
