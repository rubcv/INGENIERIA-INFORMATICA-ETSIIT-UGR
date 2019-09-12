<!DOCTYPE html>
<html lang="es">
  <head>
    <link rel="stylesheet" href="css/style.css">
    <meta charset="utf-8">
    <title> Social Network UGR </title>

    <script src="js/include.js"> </script>

     <script>

          var user_name = getCookie("name");
          var user_pass = getCookie("pass");
            alert(user_name + " --- " + user_pass);
          if(user_name != "" && user_pass != ""){
            document.getElementsByClassName("header-form")[0][0].value = user_name;
            document.getElementsByClassName("header-form")[0][1].value = user_pass;
          }
    </script>
    <style>
       body {
            font-family: 'Lato', sans-serif;
        }
    </style>
    <?php

      $EXECUTED = true;


        if(isset($_POST['SubmitButton'])){
          include_once 'conexiones/registro.php';
          echo "<script>  var myWindow = window.open(\"\", \"Welcome\", \"toolbar=yes,scrollbars=yes,resizable=yes,top=300,left=500,width=300,height=100\");
                myWindow.document.write(\"<h4>¡Gracias por registrarte en Social Network UGR! Ya puedes iniciar sesión escribiendo tus datos en el formulario de la cabecera</h4>\");
                </script>";
        }
        
      
    ?>
    
  </head>

  <body>
    
    <section class="top-header">
      <img src="images/logo.png" alt="Social Network UGR">
      <h1 class="header-letters" id="header-with-transition"> Social Network UGR </h1>
      <form class="header-form" action="portada.php" method="post" autocomplete="on">
        <section class="user-input">
          <section>
          <label><b>Usuario</b></label>
        </section>
          <section>
          <input type="text" id="user-name" placeholder="Escribe tu nombre de usuario" name="user_name">
        </section>

          <section>
          <label><b>Contraseña</b></label>
          </section>
          <input type="password" id="user-pass" placeholder="Escribe tu contraseña" name="user_password">
        </section>
        <section class="start-button">
          <input type="checkbox" id="recordar"> <b class="remember"> Recordar </b>
          <input type="submit" id="zoom-text"  onclick="return validar(this)" name="SessionStartClick" value="Inicio">
        </section>
      </form>
    </section>
    

    <section class="body-sections">
      <img src="images/image.png" alt="Social Network UGR Image">
      <form class="new-users-form" action="index.php" method="post" autocomplete="on">
          <label><b>Nombre</b></label>
        <section>
          <input type="text" id="user-name-reg" placeholder="Escribe tu nombre" name="user_firstname" required>
        </section>
          <label><b>Apellidos</b></label>
        <section>
          <input type="text" id="user-name-reg" placeholder="Escribe tus apellidos" name="user_lastname" required>
        </section>
          <label><b>Usuario</b></label>
        <section>
          <input type="text" id="user-name-reg" placeholder="Escribe tu nombre de usuario" name="user_name" required>
        </section>
            <label><b>Correo</b></label>
          <section>
            <input type="email" id="user-email" placeholder="Escribe tu correo electrónico" name="user_email" required>
         </section>
          <label><b>Contraseña</b></label>
        <section>
          <input type="password" id="user-password" placeholder="Escribe tu contraseña" name="user_password" required>
          <section>
          <input type="password" id="user-second-password" placeholder="Vuelve a escribir tu contraseña" name="user_password" required>
          </section>
        </section>
        <section class="registration-button">
          <input type="submit" onclick="return validar_registro(this);" value="Registrar" name="SubmitButton" id="zoom-text">
        </section>
      </form>
    </section>

<br>

    <section class="bottom-sections">
      <hr>
      <footer class="about"> <a href="red-social/contacto.php"> Contacto </a> - <a href="red-social/como_se_hizo.pdf"> Acerca de </a> </footer>

    </section>


    <?php 
       unset($_POST['user_firstname']);
       unset($_POST['user_lastname']);
       unset($_POST['user_name']);
       unset($_POST['user_email']);
       unset($_POST['user_password']);
    ?>

  </body>
</html>
