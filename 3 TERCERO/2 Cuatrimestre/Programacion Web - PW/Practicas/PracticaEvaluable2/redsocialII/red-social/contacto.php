<!DOCTYPE html>
<html lang="es">
  <head>
    <link rel="stylesheet" href="contacto.css">
    <link rel="stylesheet" href="../css/style.css">
    <meta charset="utf-8">
    <title> Social Network UGR </title>

      <script src="../js/include.js"> </script>

    <style>
       body {
            margin: 0;
            font-family: 'Lato', sans-serif;
        }
    </style>


  </head>

  <body>
    
    <section class="top-header">
      <img src="../images/logo.png" alt="Social Network UGR">
      <a href="../index.php">
      <h1 class="header-letters" id="header-with-transition"> Social Network UGR </h1>
      <form class="header-form" action="../portada.php" method="post" autocomplete="on">
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
      <img src="../images/image.png" alt="Social Network UGR Image">
      <br>
      <p> <b> Dirección Postal: </b> Granada 18071</p>
      <p> <b> Teléfono: </b> 555 - 39485 </p>
      <p> <b> Dirección de contacto: </b> redsocialugr@redsocialugr.com </p>
      <p> <b> Autor: </b> Rubén Calvo Villazán </p>
    </section>

    <section class="bottom-sections">
      <hr>
      <footer class="about"> <a href="contacto.php"> Contacto </a> - <a href="como_se_hizo.pdf"> Acerca de </a> </footer>

    </section>


  </body>
</html>
