

<?php
    
    require_once 'conexion.php';

    if(isset($_POST['articulos'])){
            
        echo '<section class="titulo_info">
        <h2 id="articulos_l"> Modificar artículos </h2>
        </section>';
        echo '<h3 class="opcion"> Añadir </h3>';
        echo '<form class="login_form" action="gestion.php" method="POST" enctype="multipart/form-data">
        Nombre del artículo <br> <input type="text" name="nombre_articulo"> <br><br>
        Precio <br> <input type="number" name="precio_articulo">&nbsp; &euro; <br><br>
        Foto del artículo  <input type="file" name="foto_articulo" id="foto_articulo"> <br><br>
        Disco <input type="radio" name="tipo" value="disco">
        Merchandising <input type="radio" name="tipo" value="merch"> <br><br>
        <input type="submit" value="Añadir">
        </form>
        ';

        $sql = "SELECT * FROM `articulos`";

        $result =  $mysqli->query($sql) or die($mysqli->error);

        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

        if(!empty($campos)){
        echo '<hr class="style_sep">';
        echo '<h3 class="opcion"> Modificar </h3>';
        for ($i=0; $i < sizeof($campos) ; $i++) { 
        echo '<form class="login_form" action="modificar.php" method="POST">';
        echo '<img src="'. $campos[$i]['foto'] . '" class="slides" alt="articulo"><br><br>';
        echo '<h3>'.$campos[$i]['nombre'].'</h3><input type="hidden" name="nombre_articulo_mod" value="' . $campos[$i]['nombre'] .'">';
        echo 'Precio '.$campos[$i]['precio'] .'&nbsp; &euro;<br> <input type="hidden" name="precio_articulo_mod" value="'. $campos[$i]['precio'].'"> <br>';
        echo '<input type="submit" value="Modificar"><br><br>';
        echo '</form>';

        }
        }
    }else if(isset($_POST['discos'])){
        echo '<section class="titulo_info">
                <h2 id="discografia_l"> Modificar discografía </h2>
            </section>'; 

        echo '<h3 class="opcion"> Añadir </h3>';
        echo '<form class="login_form" action="gestion.php" method="POST" enctype="multipart/form-data">
            Nombre del disco <br> <input type="text" name="nombre_disco"> <br><br>
            Año <br> <input type="number" name="año_disco"> <br><br>
            Foto <input type="file" name="foto_disco" id="foto_disco"> <br><br>
            <input type="submit" value="Añadir">
            </form>
        ';

        $sql = "SELECT * FROM `discos`";

        $result =  $mysqli->query($sql) or die($mysqli->error);

        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

        if(!empty($campos)){
        echo '<hr class="style_sep">';
        echo '<h3 class="opcion"> Modificar </h3>';
        for ($i=0; $i < sizeof($campos) ; $i++) { 
            echo '<form class="login_form" action="modificar.php" method="POST">';
            echo '<img src="'. $campos[$i]['foto'] . '" class="slides" alt="disco"><br><br>';
            echo '<h3>'.$campos[$i]['nombre'].'</h3><input type="hidden" name="nombre_disco_mod" value="' . $campos[$i]['nombre'] .'">';
            echo ''.$campos[$i]['year_s'] .'<br> <input type="hidden" name="año_mod" value="'. $campos[$i]['year_s'].'"> <br>';
            echo '<input type="submit" value="Modificar"><br><br>';
            echo '</form>';

        }
        } 
    }else if(isset($_POST['conciertos'])){
        echo '<section class="titulo_info">
               <h2 id="conciertos_l"> Modificar conciertos </h2>
            </section>';
        echo '<h3 class="opcion"> Añadir </h3>';
        echo '<form class="login_form" id ="concierto"action="gestion.php" method="POST" enctype="multipart/form-data">
            Nombre del concierto <br> <input type="text" name="nombre_concierto"> <br><br>
            Fecha del concierto <br> <input type="date" name="fecha_concierto"> <br><br>
            Hora del concierto <br> <input type="text" name="hora_concierto"> <br><br>
            Lugar del concierto <br> <input type="text" name="lugar_concierto"> <br><br>
            Descripción <br> <textarea rows="4" cols="50" name="descripcion_concierto" form="concierto"> 
                </textarea><br><br>
            Cartel <input type="file" name="cartel" id="cartel"> <br><br>
            <input type="submit" value="Añadir">
            </form>
        ';

        $sql = "SELECT * FROM `conciertos`";

        $result =  $mysqli->query($sql) or die($mysqli->error);
            
        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

        if(!empty($campos)){
            echo '<hr class="style_sep">';
            echo '<h3 class="opcion"> Modificar </h3>';
            for ($i=0; $i < sizeof($campos) ; $i++) { 
                $campos[$i]['fecha'] = date("d-m-Y", strtotime($campos[$i]['fecha']));
                echo '<form class="login_form" action="modificar.php" method="POST">';
                echo '<img src="'. $campos[$i]['cartel'] . '" class="slides" alt="cartel">';
                echo '<h3 id="nombre_conc">'.$campos[$i]['nombre'].'</h3><input type="hidden" name="nombre_concierto_mod" value="' . $campos[$i]['nombre'] .'">';
                echo '<h3>El <span id="comprar_inner1">'.$campos[$i]['fecha'].'</span><input type="hidden" name="fecha_concierto_mod" value="' . $campos[$i]['fecha'] .'">';
                echo ' &nbsp;a las <span id="comprar_inner1">'.$campos[$i]['hora'].'  </span><input type="hidden" name="hora_concierto_mod" value="' . $campos[$i]['hora'] .'">';
                echo 'en <span id="comprar_inner1">'.$campos[$i]['lugar'].'</span><input type="hidden" name="lugar_concierto_mod" value="' . $campos[$i]['lugar'] .'">';
                echo '<br><span >'.$campos[$i]['descripcion'].'</span></h3><input type="hidden" name="descripcion_concierto_mod" value="' . $campos[$i]['descripcion'] .'">';
                echo '<input type="submit" value="Modificar"><br><br>';
                echo '</form>';
        
            }
        } 
        
    }else if(isset($_POST['componentes'])){
        echo '<section class="titulo_info">
               <h2 id="componentes_l"> Modificar componentes </h2>
            </section>';
        echo '<h3 class="opcion"> Añadir </h3>';
        echo '<form class="login_form" id ="componente" action="gestion.php" method="POST" enctype="multipart/form-data">
            Nombre del componente <br> <input type="text" name="nombre_componente"> <br><br>
            Fecha de nacimiento <br> <input type="date" name="fecha_nacimiento"> <br><br>
            Reseña biográfica <br> <textarea rows="4" cols="50" name="bio_componente" form="componente"> 
                </textarea><br><br>
            Foto <input type="file" name="foto_componente" id="foto_componente"> <br><br>
            <input type="submit" value="Añadir">
            </form>
        ';

        $sql = "SELECT * FROM `componentes`";

        $result =  $mysqli->query($sql) or die($mysqli->error);
            
        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

        if(!empty($campos)){
            echo '<hr class="style_sep">';
            echo '<h3 class="opcion"> Modificar </h3>';
            for ($i=0; $i < sizeof($campos) ; $i++) { 
                $campos[$i]['nacimiento'] = date("d-m-Y", strtotime($campos[$i]['nacimiento']));
                echo '<form class="login_form" action="modificar.php" method="POST">';
                echo '<img src="'. $campos[$i]['foto'] . '" class="slides" alt="foto">';
                echo '<h3 id="nombre_conc">'.$campos[$i]['nombre'].'</h3><input type="hidden" name="nombre_componente_mod" value="' . $campos[$i]['nombre'] .'">';
                echo '<h3>Fecha de nacimiento: <span id="comprar_inner1">'.$campos[$i]['nacimiento'].'</span><input type="hidden" name="fecha_nacimiento_mod" value="' . $campos[$i]['nacimiento'] .'">';                
                echo '<br><span >'.$campos[$i]['bio_componente'].'</span></h3><input type="hidden" name="bio_componente_mod" value="' . $campos[$i]['bio_componente'] .'">';
                echo '<input type="submit" value="Modificar"><br><br>';
                echo '</form>';
        
            }
        } 
    }else if(isset($_POST['biografia'])){

        echo '<section class="titulo_info">
               <h2 id="biografia_l"> Modificar biografía </h2>
            </section>';
        echo '<h3 class="opcion"> Añadir </h3>';
        echo '<form class="login_form" id="biografia_id" action="gestion.php" method="POST">
            Año del acontecimiento (opcional) <br> <input type="text" name="year_bio"> <br><br>
            Biografía <br> <textarea rows="4" cols="100" name="biografia_texto" form="biografia_id"> 
                </textarea><br><br>
            <input type="submit" value="Añadir">
            </form>
        ';

        $sql = "SELECT * FROM `biografia`";

        $result =  $mysqli->query($sql) or die($mysqli->error);
            
        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

        if(!empty($campos)){
            echo '<hr class="style_sep">';
            echo '<h3 class="opcion"> Modificar </h3>';
            for ($i=0; $i < sizeof($campos) ; $i++) { 
                
                echo '<form class="login_form" action="modificar.php" method="POST">';
                echo '<input type="hidden" name="id_acon_mod" value="' . $campos[$i]['id'] .'">';
                echo '<h3>Fecha: <span id="comprar_inner1">'.$campos[$i]['fecha'].'</span><input type="hidden" name="fecha_acontecimiento_mod" value="' . $campos[$i]['fecha'] .'">';                
                echo '<br><span >'.$campos[$i]['texto'].'</span></h3><input type="hidden" name="biografia_mod" value="' . $campos[$i]['texto'] .'">';
                echo '<input type="submit" value="Modificar"><br><br>';
                echo '</form>';
        
            }
        }
    }else if(isset($_POST['usuarios'])){
        
        echo '<section class="titulo_info">
               <h2 id="biografia_l"> Administrar usuarios </h2>
            </section>';
        echo '<h3 class="opcion"> Añadir </h3>';
        echo '<form class="login_form" action="gestion.php" method="POST">
                Nombre <br><input type="text" name="nombre_persona"> <br><br>
                Apellidos <br> <input type="text" name="apellidos_persona"><br><br>
                Telefono <br> <input type="number" name="telf_persona"><br><br>
                Email <br> <input type="email" name="email_persona"><br><br>
                Contraseña <br> <input type="password" name="pass_persona"><br><br>
                Soy admin <input type="radio" name="tipo_persona" value="admin">
                Soy gestor <input type="radio" name="tipo_persona" value="gestor"><br><br>
            <input type="submit" value="Añadir">
            </form>
        ';

        $sql = "SELECT * FROM `admins`";

        $result =  $mysqli->query($sql) or die($mysqli->error);
            
        $campos = mysqli_fetch_all($result, MYSQLI_ASSOC);

        $sql = "SELECT * FROM `gestores`";

        $result =  $mysqli->query($sql) or die($mysqli->error);
            
        $campos2 = mysqli_fetch_all($result, MYSQLI_ASSOC);

        if(!empty($campos)){
            echo '<hr class="style_sep">';
            echo '<h3 class="opcion"> Modificar admins</h3>';
            for ($i=0; $i < sizeof($campos) ; $i++) { 
                
                echo '<form class="login_form" action="modificar.php" method="POST">';
                echo '<h3>Nombre: '.$campos[$i]['nombre'].'</h3><input type="hidden" name="nombre_pers_mod" value="' . $campos[$i]['nombre'] .'">';
                echo '<h3>Apellidos: '.$campos[$i]['apellidos'].'</h3><input type="hidden" name="apellidos_pers_mod" value="' . $campos[$i]['apellidos'] .'">';
                echo '<h3>Telefono: '.$campos[$i]['telefono'].'</h3><input type="hidden" name="telefono_pers_mod" value="' . $campos[$i]['telefono'] .'">';                
                echo '<input type="hidden" name="tipo" value="admin">';
                echo '<h3>Email: '.$campos[$i]['email'].'</h3><input type="hidden" name="email_pers_mod" value="' . $campos[$i]['email'] .'">';                
                echo '<input type="submit" value="Modificar"><br><br>';
                echo '</form>';
        
            }
        }

        if(!empty($campos2)){
            echo '<hr class="style_sep">';
            echo '<h3 class="opcion"> Modificar gestores</h3>';
            for ($i=0; $i < sizeof($campos2) ; $i++) { 
                
                echo '<form class="login_form" action="modificar.php" method="POST">';
                echo '<h3>Nombre: '.$campos2[$i]['nombre'].'</h3><input type="hidden" name="nombre_pers_mod" value="' . $campos2[$i]['nombre'] .'">';
                echo '<h3>Apellidos: '.$campos2[$i]['apellidos'].'</h3><input type="hidden" name="apellidos_pers_mod" value="' . $campos2[$i]['apellidos'] .'">';
                echo '<h3>Telefono: '.$campos2[$i]['telefono'].'</h3><input type="hidden" name="telefono_pers_mod" value="' . $campos2[$i]['telefono'] .'">';                
                echo '<input type="hidden" name="tipo" value="gestor">';
                echo '<h3>Email: '.$campos2[$i]['email'].'</h3><input type="hidden" name="email_pers_mod" value="' . $campos2[$i]['email'] .'">';                
                echo '<input type="submit" value="Modificar"><br><br>';
                echo '</form>';
        
            }
        }

    }else{
        header("Location: gestion.php");
    }
?>