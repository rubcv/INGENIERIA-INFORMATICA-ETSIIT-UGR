
			<!-- ---------------------------------------------------------- -->

			<section class="titulo_info">
					<h2> Discografía del artista </h2>
				</section>
				

				<?php
					require_once 'database/conexion.php';
					
					function custom_sort($a,$b) {
						return $a['nombre']>$b['nombre'];
				   	};
					
					$sql = "SELECT * FROM `discos`";
					$result =  $mysqli->query($sql) or die($mysqli->error);
					$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
					
					echo '<section id="discografia">';
					if(!empty($campos)){
						
						for ($i=0; $i < sizeof($campos) ; $i++) { 
							echo "<br>";
							echo '<img src="' . $campos[$i]['foto'] . '" class="slides_disco" alt="disco">';
							
							$disco = $campos[$i]['nombre'];
							$year = $campos[$i]['year_s'];
							echo '<section class="disco_name"></section>';
							
							$sql = "SELECT * FROM `canciones` WHERE disco = '$disco'";
							$result =  $mysqli->query($sql) or die($mysqli->error);
							$campos2 = mysqli_fetch_all($result, MYSQLI_ASSOC);
							
							if(!empty($campos2)){
								
								usort($campos2, "custom_sort");
								
								echo '<section class="canciones_lista_disco">';
								echo '<h3 >'. $disco .' (' . $year.')</h3>';
								for ($j=0; $j < sizeof($campos2) ; $j++) { 
									echo $campos2[$j]['nombre'] . " (" . $campos2[$j]['duracion'] . ")<br>";
								}
								echo '</section>';
								
							}
							
							$disco = preg_replace('/\s+/', '', $disco);

							echo '<button type="button"  class="buyBtt '. $disco. '" > Comprar </button><br>';
							$disco = "imprimir" . $disco;
							echo '<section class="'.$disco.'"></section>';
						}
					}	
					
					echo '</section>';
					?>
				
			
			<!-- ---------------------------------------------------------- -->
