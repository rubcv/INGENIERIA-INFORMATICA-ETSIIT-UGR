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
            if(isset($_GET['error'])){
                echo '<h4 id="error_msg"> El usuario no existe </h4>';
                unset($_GET['error']);
            }
        ?>
    <section> 
        <fieldset>
            <legend> <strong> <h3> Login  </h3> </strong> </legend>
            <form action="portal.php" method="POST">
                Email: <input type="email" name="email"> <br> <br>
                Contraseña: <input type="password" name="pass"> <br> <br>
                <input type="submit" value="Enviar" id="enviar">
        </fieldset>
            </form>
            <p> Cuenta admin: </p> 
            <strong> Correo: </strong> admin@gmail.com <br>
            <strong> Password: </strong> p12 </br>
            <p> Cuenta normal: </p> 
            <strong> Correo: </strong> prueba@gmail.com <br>
            <strong> Password: </strong> p12 </br>
    </section>
</body>
</html>