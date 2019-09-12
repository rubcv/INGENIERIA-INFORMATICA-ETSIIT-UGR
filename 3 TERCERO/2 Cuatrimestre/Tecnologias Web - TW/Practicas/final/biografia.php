
			<!-- ---------------------------------------------------------- -->
			<section id="biografia">
				<section class="titulo_info">
					<h2> Biografía </h2>
				</section>	

				<?php
					require_once 'database/conexion.php';
					
					$sql = "SELECT * FROM `componentes`";

					$result =  $mysqli->query($sql) or die($mysqli->error);
						
					$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

					function custom_sort($a,$b) {
						return $a['fecha']>$b['fecha'];
				   	};

					if(!empty($campos)){
					   
					   for ($i=0; $i < sizeof($campos) ; $i++) {
						   echo '<img src="' . $campos[$i]['foto'] .'">';
					   }
				   }

					$sql = "SELECT * FROM `biografia`";

					$result =  $mysqli->query($sql) or die($mysqli->error);

					$campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
					
					if(!empty($campos)){
						
						// Ordenamos por fecha
						usort($campos, "custom_sort");
						
					
						
						for ($i=0; $i < sizeof($campos) ; $i++) {
							echo '<h3>' . $campos[$i]['fecha'] .'</h3>';
							echo '<p>' . $campos[$i]['texto'] . '</p>';
						}
					}



				?>
					
				
			</section>
			
			<!-- ---------------------------------------------------------- -->
