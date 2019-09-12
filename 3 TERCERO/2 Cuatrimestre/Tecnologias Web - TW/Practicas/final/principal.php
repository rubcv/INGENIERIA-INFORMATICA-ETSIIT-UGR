<?php

require_once 'database/conexion.php';



   echo '<section class="titulo_info">
				<h2> Synopsis </h2>
			</section>
			<section id="sinopsis">';
					
						 $sql = "SELECT * FROM `componentes`";

						 $result =  $mysqli->query($sql) or die($mysqli->error);
							 
						 $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

						 if(!empty($campos)){
							
							for ($i=0; $i < sizeof($campos) ; $i++) {
								echo '<h4>'.$campos[$i]['nombre'] . '</h4>';
								echo $campos[$i]['bio_componente'];
							}
						}


            echo '<h4> Algunos éxitos </h4>';
            
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

			echo '</section>

    <section class="titulo_info">
        <h2> Próximas giras </h2>
        <section id="giras">';

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
echo ' 
        </section>
    </section>
    ';


        

          $sql = "SELECT * FROM `articulos`";

          $result =  $mysqli->query($sql) or die($mysqli->error);
              
          $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

          
echo '

<script>
        var nombre = new Array();
        var precio = new Array();

        '; for ($i=0; $i < sizeof($campos) ; $i++) { 
               echo 'nombre.push(' . $campos[$i]['nombre'] . ');';
               echo 'precio.push(' . $campos[$i]['precio'] . ');';
         } 
echo '</script>';

echo '
<section class="titulo_info">
    <h2> Tienda </h2>
</section>
        <section class="centrado">';
            
                for ($i=0; $i < sizeof($campos); $i++) { 
                    echo '<img class="slides" src="'. $campos[$i]['foto'] .'" alt="imagen">';
                }
            
        echo '    
        </section>
        ';
            if(!empty($campos)){
                echo '<section id="a_tienda">
                        <h4>  <a href="tienda.php"> Comprar <span id="comprar_inner1"> </span> por tan sólo <span id="comprar_inner2"> </span> &euro; </a></h4>
                     </section>';

                echo '<section id="promo">
                        <h4> ¡Aprovecha esta oportunidad! </h4>
                    </section>
                    ';
            }
  echo '
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
            
            
            setTimeout(carousel, 2500); 
            document.getElementById("comprar_inner1").innerHTML = nombre[myIndex % nombre.length] ;					
            document.getElementById("comprar_inner2").innerHTML = precio[myIndex % precio.length] ;
        }
    </script>
    </a>
    </section>';
?>