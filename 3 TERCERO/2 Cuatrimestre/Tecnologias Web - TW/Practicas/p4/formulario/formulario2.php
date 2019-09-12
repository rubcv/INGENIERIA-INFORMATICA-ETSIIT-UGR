<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>EDITODO</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
  
</head>
<body>
    <?php

        function comprobarVariables (){
            $completo = true;

            if(
                !isset($_POST['nombre']) || $_POST['nombre'] == "" ||
                !isset($_POST['apellidos']) || $_POST['apellidos'] == "" ||
                !isset($_POST['calle']) || $_POST['calle'] == "" ||
                !isset($_POST['telefono']) || $_POST['telefono'] == "" ||
                !isset($_POST['fecha_nac']) || $_POST['fecha_nac'] == "" ||
                !isset($_POST['email']) || $_POST['email'] == "" ||
                !isset($_POST['cc']) || $_POST['cc'] == "" ||
                !isset($_POST['revista']) || $_POST['revista'] == "" ||
                !isset($_POST['anual'])   || $_POST['anual'] == "" ||
                !isset($_POST['pago']) ||  $_POST['pago'] == ""
                

            ){
                $completo = false;
            }
            
            if(isset($_POST['pago']) && $_POST['pago'] == "reembolso"){

                if(
                    !isset($_POST['tipotarj']) || $_POST['tipotarj'] == "" ||
                    !isset($_POST['numtarj'])  || $_POST['numtarj'] == "" ||
                    !isset($_POST['caducidad']) || $_POST['caducidad'] == "" ||
                    !isset($_POST['cvc'])  || $_POST['cvc'] == ""
                ){
                    $completo = false;
                }
            }
            
            return $completo;
        }


        function comprobarTexto($texto){
            if (!preg_match('/[^A-Za-z0-9]/', $texto)){
                return true;                
            }
            
            return false;
        }

        function comprobarNacimiento($fecha){
             
            $fecha = strtotime($fecha);
            
            $edad = strtotime('+18 years', $fecha);
        
            if(time() < $edad)  {
                return false; 
            }
            
            return true;           
        }

        function comprobarTelefono($telefono){
            if(preg_match("/^[0-9]{9}$/", $telefono)){
                return true;
            }
            return false;    
        }

        function comprobarEmail($email){
            if(preg_match("/(^[a-zA-Z][\w\_\\-])+[\w]+[@][a-z]+(\.[a-z]+)*\.[a-z]{2,3}/", $email)){
                return true;
            }            
            return false;
        }

        function comprobarCC($cc){
                return is_numeric($cc);
        }

        function comprobarCaducidad($caducidad){
            $caduca = new DateTime($caducidad);
            $ahora = new DateTime();    
            
            return ($caduca > $ahora);
        }

        function comprobarCVC($cvc){
            if(preg_match( "/^[(\d)]{3}$/", $cvc)){
                return true;
            }            
            return false;    
           
        }

        function sticky($valor, $tipo){

            if(isset($valor) && !formulario2vacio()){

                if($tipo == 'texto'){
                    if(comprobarTexto($valor)){
                        return $valor;
                    }
            
                }else if($tipo == "fecha"){
                    if(comprobarNacimiento($valor)){
                        return $valor;
                    }
                }else if($tipo == "telefono"){
                    if(comprobarTelefono($valor)){
                        return $valor;
                    }
                }else if($tipo == "email"){
                    if(comprobarEmail($valor)){
                        return $valor;
                    }
                }else if($tipo == "cc"){
                    if(comprobarCC($valor)){
                        return $valor;
                    }
                }else if($tipo == "cvc"){
                    if(comprobarCVC($valor)){
                        return $valor;
                    }
                }else if($tipo == "caducidad"){
                    if(comprobarCaducidad($valor)){
                        return $valor;
                    }
                }
            }
        }


        function formulario2vacio(){
            $vacio = true;

            if(
                isset($_POST['nombre']) && $_POST['nombre'] != "" ||
                isset($_POST['apellidos']) && $_POST['apellidos'] != "" ||
                isset($_POST['calle']) && $_POST['calle'] != "" ||
                isset($_POST['telefono']) && $_POST['telefono'] != "" ||
                isset($_POST['fecha_nac']) && $_POST['fecha_nac'] != "" ||
                isset($_POST['email']) && $_POST['email'] != "" ||
                isset($_POST['cc']) && $_POST['cc'] != "" ||
                isset($_POST['revista']) && $_POST['revista'] != "" ||
                isset($_POST['anual'])   && $_POST['anual'] != "" ||
                isset($_POST['pago']) &&  $_POST['pago'] != ""
                

            ){
                $vacio = false;
            }
            
            return $vacio;
        }

     

    ?>
    
    
    <section> 
        <h1> EDITODO </h1>

        <?php

            
           
            // Vengo del formulario 2

            if(comprobarVariables() && // Muestras el resultado
                   comprobarTexto($_POST['nombre']) &&
                   comprobarTexto($_POST['apellidos']) &&
                   comprobarTexto($_POST['calle']) &&
                   comprobarTexto($_POST['tipotarj']) &&
                   comprobarNacimiento($_POST['fecha_nac']) &&
                   comprobarTelefono($_POST['telefono']) &&
                   comprobarEmail($_POST['email']) &&
                   comprobarCC($_POST['cc']) &&
                   comprobarTexto($_POST['revista']) 
            ){
                    echo "<h1> Información recibida </h1>";
                    
                    echo "<h3> Información personal </h3>";
                    echo "<h4> Nombre: </h4> " . $_POST['nombre'] ;
                    echo "<h4> Apellidos: </h4>" . $_POST['apellidos'];
                    echo "<h4> Calle: </h4>" . $_POST['calle'] ;
                    echo "<h4> Fecha nacimiento: </h4>" . $_POST['fecha_nac'] ;
                    echo "<h4> Telefono: </h4>" . $_POST['telefono'] ;
                    echo "<h4> Email: </h4>" . $_POST['email'] ;
                    echo "<h4> CC: </h4>" . $_POST['cc'] ;

                    echo "<h3> Información sobre la suscripción </h3>";
                    echo "<h4> Revista: </h4>" . $_POST['revista'] ;
                    echo "<h4> Suscripción: </h4>" . $_POST['anual'] ;

                    echo "<h3> Modo de pago </h3>";
                    echo "<h4> Pago: </h4>" . $_POST['pago'] . "</h4>";
                    if(isset($_POST['divulg'])){$divulg = $_POST['divulg'];}else{$divulg = "";}
                    if(isset($_POST['motor'])){$motor = $_POST['motor'];}else{$motor = "";}
                    if(isset($_POST['viajes'])){$viajes = $_POST['viajes'];}else{$viajes = "";}
                    echo "<h4> Temas de interés: </h4>" . $divulg . " " . $motor . " " . $viajes . " " ;
                    echo "<h4> Publicidad: </h4>" . $_POST['publi'] ;


            }else{ // Muestras el formulario



                if(isset($_POST['area'])){ // Vengo del formulario 1 completo
                
                    if(preg_match('/\d/', $_POST['area'])){
                        header ("Location: formulario.php?error=true");
                        exit;
                    }
    
    
                }else if(!isset($_POST['area']) && formulario2vacio()){ // Vengo del formulario 1 sin completar
                    header("Location: formulario.php?error=true");
    
                }

                $area = $_POST['area'];
                echo '<h4> Rellena los siguientes datos para suscribirte a <span id="ok_msg">' . $_POST['area'] . ' </span></h4>';
                
                // Formulario
                if(!formulario2vacio()){
                    $nombre = sticky($_POST['nombre'], 'texto');
                    $apellidos = sticky($_POST['apellidos'], 'texto');
                    $calle = sticky($_POST['calle'], 'texto');
                    $nacimiento = sticky($_POST['fecha_nac'], 'fecha');
                    $telefono = sticky($_POST['telefono'], 'telefono');
                    $email =  sticky($_POST['email'], 'email');
                    $cc = sticky($_POST['cc'], 'cc');
                }else{
                    $nombre = "";
                    $apellidos = "";
                    $calle = "";
                    $nacimiento = "";
                    $telefono = "";
                    $email = "";
                    $cc = "";
                }

                echo '<form action="formulario2.php" method="POST"> '; 
                echo       ' <fieldset> ';
                echo       ' <legend> Información personal </legend> ';
                echo "<input type='hidden' name='area' value='$area'>"; 
                echo       ' Nombre: <br> <input type="text" name="nombre" value="' . $nombre .'"> <br> <br> ';
                echo       ' Apellidos:<br> <input type="text" name="apellidos" value="' . $apellidos .'" > <br><br> ';
                echo       ' Direccion Postal: <br><input type="text" name="calle" value="' . $calle .'" > <br><br> ';
                echo       ' Fecha nacimiento: <br> <input type="date" name="fecha_nac" value="' .  $nacimiento .'" > <br><br> ';
                echo       ' Telefono: <br> <input type="tel" name="telefono" value="' . $telefono .'" > <br><br> ';
                echo       ' Email: <br> <input type="email" name="email" value="' . $email .'" > <br><br> ';
                echo       ' CC: <br> <input type="number" name="cc" value="' . $cc .'" > <br> <br> ';
                echo       ' </fieldset> ';
                echo        '<fieldset>
                <legend> Información sobre la suscripcion </legend>';
                
                echo '<p> Suscripción a <span id="ok_msg"> ' . $_POST['area'] . '</span> </p>';
                if($_POST['area'] == "divulgacion"){
                    echo '<select name="revista" size="4">
                    <option value="sabelotodo">Sabelotodo</option>
                    <option value="nosenada">Solo se que no se nada</option>
                    <option value="interesado">Muy interesado</option>
                    <option value="ciencia">Ciencia con sabor</option>
                    </select> ';
                    
                }else if($_POST['area'] == "motor"){
                    echo '<select name="revista" size="3">
                    <option value="supercoches">Supercoches</option>
                    <option value="pillo">Corre que te pillo</option>
                    <option value="carretera">El mas lento de la carretera</option>
                    </select> ';
                }else if($_POST['area'] == "viajes"){
                    echo '<select name="revista" size="3">
                    <option value="paraisos">Paraisos del mundo </option>
                    <option value="ciudad">Conoce tu ciudad </option>
                    <option value="vecino">La casa de tu vecino: rincones inhóspitos</option>
                    </select> ';
                }
                
                echo '</strong> <br> <br>
                Anual: <input type="radio" name="anual" value="anual">
                Bianual: <input type="radio" name="anual" value="bianual">
                
                <br><br> <strong> Modo de pago: </strong> <br>
                Tarjeta <input type="radio" name="pago" value="tarjeta"> <br>
                Reembolso <input type="radio" name="pago" value="reembolso"> <br> 
                <h4> Con tarjeta: </h4>
                Tipo de tarjeta <input type="text" name="tipotarj"> <br> <br> 
                Numero de tarjeta <input type="text" name="numtarj"> <br><br> 
                Mes/Año caducidad <input type="month" name="caducidad"> <br><br> 
                Codigo CVC <input type="number" name="cvc"> <br><br>
                
                </fieldset> ';
                
                
                echo '
                <fieldset>
                <legend> Otra información </legend>
                <h4> Temas de interés </h4>
                Divulgación <input type="checkbox" name="divulg" value="divulgación"> <br> 
                Motor <input type="checkbox" name="motor" value="motor"> <br>
                Viajes <input type="checkbox" name="viajes" value="viajes"> <br><br> 
                
                <i> Enviarme publicidad </i><input type="checkbox" name="publi" value="Si"> <br><br> 
                </fieldset><br>
                <input type="submit" value="Enviar" id="enviar">
                </form> ';
            
            }
    

        ?>

    </section>
</body>
</html>
