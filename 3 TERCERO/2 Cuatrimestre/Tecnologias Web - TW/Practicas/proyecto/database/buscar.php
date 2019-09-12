<?php
    
    require_once 'conexion.php';


    // IMPORTANTE: Ver explicacion sobre AJAX en index.php

    if(isset($_POST['campo']) && $_POST['campo'] == 'discos'){ // Si busca discos mostramos inputs de fecha edicion
        echo '<br>editado entre <input type="text" class="contenido2" id="fecha_ini" name="fecha_ini">
         y <input type="text" class="contenido2" id="fecha_fin" name="fecha_fin"> (dejar en blanco para buscar también canciones)<br><br>  ';
         echo '<button type="submit" class="BusquedaBtt" id="database/buscar.php"> Buscar </button> <br><br>';
    }else if(isset($_POST['campo']) && $_POST['campo'] == 'conciertos'){ // Si busca conciertos mostramos lugar y fecha
        
        $sql = "SELECT lugar FROM `conciertos`";

        $result =  $mysqli->query($sql) or die($mysqli->error);
                            
        
        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
        
        echo '<br>con lugar en '.
            '<select id="lugarconc" class="contenido2">';
            for ($i=0; $i < sizeof($campos); $i++) { 
                echo '<option value="' . $campos[$i]['lugar'] .'">' . $campos[$i]['lugar'] . '</option>';
            }
        echo '</select>';
        echo ' celebrado entre (yyyy-mm-dd) <input type="text" class="contenido2" id="fecha_ini" name="fecha_ini">
         y <input type="text" class="contenido2" id="fecha_fin" name="fecha_fin"><br><br>  ';
         echo '<button type="submit" class="BusquedaBtt" id="database/buscar.php"> Buscar </button> <br><br>';
    }else if(!isset($_POST['campo']) && !isset($_POST['buscar'])){ // Si no ha seleccionado, mostramos input de seleccion
        echo ' Buscar <input type="text" class="contenido2" name="buscar" id="nombre_bus"> en
                <select id="campoBus" class="contenido2">
                <option value="discos">Discos</option>
                <option value="conciertos">Conciertos</option>
            </select> (desplegar para búsqueda avanzada) &#8595; <br><br>';
    }


    if(isset($_POST['buscar']) && $_POST['buscar'] != ""){ // Si ha dado a buscar
       
        $nombre = $_POST['buscar'];
        
        echo '<span id="negrita"> Resultados obtenidos </span><br><br>';
        
        if(isset($_POST['lugar'])){ // Buscamos un concierto
            
            $lugar = $_POST['lugar'];

            // Comprobamos las fechas introducidas
            if(isset($_POST['fecha_ini']) && $_POST['fecha_ini'] != "" && isset($_POST['fecha_fin']) && $_POST['fecha_fin'] != ""){
                $ini = $_POST['fecha_ini'];
                $fin = $_POST['fecha_fin'];

                $sql = "SELECT * FROM `conciertos` WHERE  lugar = '$lugar' AND fecha >= '$ini' AND fecha <= '$fin';";
            }else if(isset($_POST['fecha_ini']) && $_POST['fecha_ini'] != "" ){
                $ini = $_POST['fecha_ini'];
                
                $sql = "SELECT * FROM `conciertos` WHERE lugar = '$lugar' AND fecha >= '$ini';";

            }else if(isset($_POST['fecha_fin']) &&  $_POST['fecha_fin'] != ""){
                $fin = $_POST['fecha_fin'];
                
                $sql = "SELECT * FROM `conciertos` WHERE lugar = '$lugar' AND fecha <= '$fin';";
            }else{
                $sql = "SELECT * FROM `conciertos` WHERE lugar = '$lugar';";
            }

            $result =  $mysqli->query($sql) or die($mysqli->error);
            $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

            if(!empty($campos)){
    
                for ($i=0; $i < sizeof($campos) ; $i++) { // Mostramos los que contengan el nombre
                    if(strpos($campos[$i]['nombre'], $nombre) !== false){ 
                        echo '<span class="color_azul_osc">Nombre: </span>' . $campos[$i]['nombre'] . '<br>';
                        echo '<span class="color_azul_osc">Fecha del concierto: </span>' . $campos[$i]['fecha'] . '<br>';
                        echo '<span class="color_azul_osc">Lugar: </span>' . $campos[$i]['lugar'] . '<br>';
                        echo '<span class="color_azul_osc">Hora: </span>' . $campos[$i]['hora'] . '<br>';
                    }
                }

            }else{
                echo 'Sin resultados';
            }


        }else{ // Buscamos un disco
            
            $sql2 = "";
            if(isset($_POST['fecha_ini']) && $_POST['fecha_ini'] != "" && isset($_POST['fecha_fin']) && $_POST['fecha_fin'] != ""){
                $ini = $_POST['fecha_ini'];
                $fin = $_POST['fecha_fin'];

                $sql = "SELECT * FROM `discos` WHERE  year_s >= '$ini' AND year_s <= '$fin';";

            }else if(isset($_POST['fecha_ini']) && $_POST['fecha_ini'] != ""){
                $ini = $_POST['fecha_ini'];
                
                $sql = "SELECT * FROM `discos` WHERE  year_s >= '$ini';";
    
            }else if(isset($_POST['fecha_fin']) && $_POST['fecha_fin'] != ""){
                $fin = $_POST['fecha_fin'];
                
                $sql = "SELECT * FROM `discos` WHERE year_s <= '$fin';";
    
            }else{ // Si no hay fecha introducida, buscamos tambien en canciones
                $sql = "SELECT * FROM `discos`;";
                $sql2 = "SELECT * FROM `canciones`;";
            }

            if($sql2 == ""){ // Si sql2 == "" es que ha introducido fecha

                $result =  $mysqli->query($sql) or die($mysqli->error);
                $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);
    
                if(!empty($campos)){
        
                    for ($i=0; $i < sizeof($campos) ; $i++) { // Mostramos los que contengan el nombre
                        if(strpos($campos[$i]['nombre'], $nombre) !== false){
                            echo '<span class="color_azul_osc">Nombre: </span>' . $campos[$i]['nombre'] . '<br>';
                            echo '<span class="color_azul_osc">Edición: </span>' . $campos[$i]['year_s'] . '<br><br>';
                        }
                    }
    
                }else{
                    echo 'Sin resultados';
                }
            }else{
                $result =  $mysqli->query($sql) or die($mysqli->error);
                $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

                $result =  $mysqli->query($sql2) or die($mysqli->error);
                $campos2 = mysqli_fetch_all($result, MYSQLI_ASSOC);
    
                echo '<span id="negrita">Discos: </span><br>'; // Mostramos los discos encontrados
                if(!empty($campos)){
                    for ($i=0; $i < sizeof($campos) ; $i++) { 
                        if(strpos($campos[$i]['nombre'], $nombre) !== false){
                            echo '<span class="color_azul_osc">Nombre: </span>' . $campos[$i]['nombre'] . '<br>';
                            echo '<span class="color_azul_osc">Edición: </span>' . $campos[$i]['year_s'] . '<br><br>';
                        }
                    }
    
                }else{
                    echo 'Sin resultados<br>';
                }

                echo '<span id="negrita">Canciones: </span><br>'; // Mostramos las canciones encontradas
                if(!empty($campos2)){
                    for ($i=0; $i < sizeof($campos2) ; $i++) { 
                        if(strpos($campos2[$i]['nombre'], $nombre) !== false){
                            echo '<span class="color_azul_osc">Nombre: </span>' . $campos2[$i]['nombre'] . '<br>';
                            echo '<span class="color_azul_osc">Disco: </span>' . $campos2[$i]['disco'] . '<br>';
                            echo '<span class="color_azul_osc">Duración: </span>' . $campos2[$i]['duracion'] . '<br><br>';
                        }
                    }
    
                }else{
                    echo 'Sin resultados';
                }
            }

        }

    
        echo '<br><br>';
       

    }

                        
?>