<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Portal Web</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="main.css" />
  
</head>
<body>

    <?php

        require_once 'conexion.php';
        session_start();

        function validoLogin($email, $pass, $mysqli){
            
            if(!filter_var($email, FILTER_VALIDATE_EMAIL)){
                return false;
            }else{
                $sql = "SELECT clave_cifrada FROM `usuarios` WHERE email = '$email';";
                $result =  $mysqli->query($sql) or die($mysqli->error);
                    
                $row = $result->fetch_row();

                $pass_guardada = $row[0];

               $pass = base64_encode($pass);
               
                if($pass_guardada != $pass){
                    return false;
                }
            }

            return true;
        }



        if( isset($_POST['email']) &&
            isset($_POST['pass']) &&
            !isset($_GET['error'])){
                
                if(validoLogin($_POST['email'], $_POST['pass'], $mysqli)){
                    

                    $email = $mysqli->real_escape_string($_POST['email']);
                    $pass =  $mysqli->real_escape_string($_POST['pass']); 

                    $pass =  base64_encode($pass);

                    $sql = "SELECT * FROM `usuarios` WHERE email = '$email' AND clave_cifrada = '$pass';";
            
                    $result =  $mysqli->query($sql) or die($mysqli->error);
                    
                    $row = $result->fetch_row();
                
                   

                    $_SESSION['email'] = $row[0];
                    $_SESSION['nombre'] = $row[1];
                    $_SESSION['apellidos'] = $row[2];
                    $_SESSION['clave_cifrada'] = $row[3];
                    $_SESSION['tipo'] = $row[4];
                    
                  }else{
                     header("Location: usuarios.php?error=true");
                  }

            }else if(   !isset($_POST['email']) &&
                        !isset($_POST['pass']) &&
                        !isset($_GET['error'])){
                header("Location: usuarios.php?error=true");
            }

   
      
        
        if($_SESSION['tipo'] == 'admin'){
            
            if(isset($_GET['error'])){
                if($_GET['error']){
                    echo '<h4 id="ok_msg"> Usuario creado </h4>';
                }else{
                    echo '<h4 id="error_msg"> Usuario no creado </h4>';
                }
            }

            echo '<a href="cerrar_sesion.php" id="close"> Cerrar sesion </a>'; 

            echo '<section> 
                    <fieldset>
                        <legend> <strong> <h3> Registro  </h3> </strong> </legend>
                        <form action="registro.php" method="POST">
                            Nombre: <input type="text" name="nombre"> <br> <br>
                            Apellidos: <input type="text" name="apellidos"> <br> <br>
                            Email: <input type="email" name="email"> <br> <br>
                            Contraseña: <input type="password" name="pass"> <br> <br>
                            Soy admin: <input type="checkbox" name="admin"> <br> <br>
                            <input type="submit" value="Enviar" id="enviar">
                        </form>
                    </fieldset>
                </section>';

                
        }else{
            echo '<a href="cerrar_sesion.php" id="close"> Cerrar sesion </a>';
        }


    ?>

</body>
</html>