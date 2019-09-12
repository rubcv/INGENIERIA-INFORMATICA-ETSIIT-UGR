
			<!-- ---------------------------------------------------------- -->

			<section class="titulo_info">
					<h2> Discografía del artista </h2>
				</section>
				

				<?php
					require_once 'database/conexion.php';
					
					function custom_sort($a,$b) { // Función que ordena alfabéticamente por nombre
						return $a['nombre']>$b['nombre'];
				   	};
					
					$sql = "SELECT * FROM `discos`"; // Recogemos los discos
					$result =  $mysqli->query($sql) or die($mysqli->error);
					$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
					
					echo '<section id="discografia">';
					if(!empty($campos)){
						
						for ($i=0; $i < sizeof($campos) ; $i++) { // Para cada disco
							echo "<br>";
							echo '<img src="' . $campos[$i]['foto'] . '" class="slides_disco" alt="disco">'; // Foto
							
							$disco = $campos[$i]['nombre'];
							$year = $campos[$i]['year_s'];
							echo '<section class="disco_name"></section>';
							
							$sql = "SELECT * FROM `canciones` WHERE disco = '$disco'"; // Extraemos las canciones del disco
							$result =  $mysqli->query($sql) or die($mysqli->error);
							$campos2 = mysqli_fetch_all($result, MYSQLI_ASSOC);
							
							
							usort($campos2, "custom_sort"); // Ordenamos las canciones alfabéticamente
							
							echo '<section class="canciones_lista_disco">';
							echo '<h3 >'. $disco .' (' . $year.')</h3>';
								if(!empty($campos2)){
									for ($j=0; $j < sizeof($campos2) ; $j++) { // Mostramos las canciones
										echo $campos2[$j]['nombre'] . " (" . $campos2[$j]['duracion'] . ")<br>";
									}
								
								}
							echo '</section>';
							
							// Mostramos el botón de compra de cada disco
							
							// Como la compra la hacemos con AJAX, para cada disco se hace la petición con su nombre
							// Extrayéndolo del atributo clase del button con JS, por lo tanto le quitamos 
							// los espacios para que todo el nombre sea la clase
							$disco = preg_replace('/\s+/', '', $disco);

							echo '<button type="button"  class="buyBtt '. $disco. '" > Comprar </button><br>';
							$disco = "imprimir" . $disco;
							echo '<section class="'.$disco.'"></section>'; // En este section se pega el html del
																			// formulario de compra del disco
						}
					}	
					
					echo '</section>';
					?>
				
			
			<!-- ---------------------------------------------------------- -->
