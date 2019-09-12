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
    <section> 
        <h1> EDITODO </h1>

        <h3> Saludos, selecciona el área  a la que te deseas suscribir: </h3>

        <?php
            if(isset($_GET['error'])){
                echo "<h4 id='error_msg'> <i> Error al enviar el formulario </i> </h4>";
                unset($_GET['error']);
            }
        ?>
            
        <form action="formulario2.php" method="POST">
            <select name="area" size="3">
                <option value="divulgacion">Divulgación</option>
                <option value="motor">Motor</option>
                <option value="viajes">Viajes</option>
            </select> <br> <br>
            <input type="submit" value="Enviar">
        </form>
    </section>
</body>
</html>