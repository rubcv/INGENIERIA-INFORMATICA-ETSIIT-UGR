<!DOCTYPE html>
<html lang="es">
  <head>
    <link rel="stylesheet" href="css/usuarios-style.css">
    <meta charset="utf-8">
    <title>Usuario: Social Network UGR </title>
    <script src="https://code.jquery.com/jquery-3.2.1.js"> </script>

    <?php
         include("conexiones/sesion.php"); 

          if (!isset($_SESSION["username"])){
           header("location: index.php");
          }
    ?>
    <script src="js/include.js"> </script>

      <style>
        body {
            margin: 0;
            font-family: 'Lato', sans-serif;
        }
         .entradas{
          width: 1210px;
          overflow-y:scroll;
        }
        .recent-users {
          overflow-y:scroll;
           z-index: 0.5;
        }

        #cambiar_foto{
          margin-left: 250px;
          margin-top: 130px;
        }
        #borrar_usuario{
          margin-left: 400px;
          margin-top: -155px;
        }

        .wideInput{
            text-align: left;
            padding-left:0;
            padding-top:1;
            margin-top:10px;
            padding-bottom:0.4em;
            padding-right: 0.4em;
            width: 500px;
            height: 50px;
        }
        #recent-user-name {
          font-size: 1.2em;
          margin-bottom: -40px;
          margin-top: -20px;
          text-align: center;
        }
      #entry-user-name {
        font-size: 1.2em;
        margin-bottom: -20px;
        margin-top: 20px;
        text-align: center;
      }
      #entrada-box h4{
        font-size: 1em;
        margin-top: -20px;
        margin-bottom: -7px;
      }
       .entry-user-name2 {
        font-size: 1.5em;
         margin-left: -800px;
        margin-bottom: -10px;
        margin-top: 20px;
        text-align: center;
      }
      #recent-user-picture2 {
          width: 80px;
          height: 80px;
          margin-left: -800px;
          margin-top: -15px;
          border-radius: 0.7rem;
        }
        .entrada-nueva{
          margin-top:-100px;
          padding-bottom: 20px;
        }
        .titulo{
          width: 250px;
        }

        #foto_us{
            width: 400px;
            height: 400px;
            margin-left: -750px;
            margin-top: 20px;
            border-radius: 0.7rem;
            border-style: dashed;
            border-color: #f48c42;
        }
        #info_per{
            margin-top: -300px;
            margin-left: 450px;
            text-align: left;
        }
        #info_per input{
            width: 230px;
        }
        #activo{
            margin-left: -750px;
        }
        #info-us{
            text-align: left;
            margin-left: 450px;
            margin-top: -300px;
        }
        #amigo{
          margin-left: -200px;
          margin-top: 50px;
        }

          
          .button {
              position: relative;
              background-color: rgba(244, 152, 66, 0.9);
              border: dashed;
              font-size: 18px;
              color: #FFFFFF;
              padding-right: 20px;
              width: 150px;
              height: 100px;
              margin-left:-18px;
              text-align: center;
              transition-duration: 0.4s;
              text-decoration: none;
              overflow: hidden;
              cursor: pointer;
          }

          .button:after {
              content: "";
              background: #f1f1f1;
              display: block;
              position: absolute;
              padding-top: 300%;
              padding-left: 350%;
              margin-left: -20px;
              margin-top: -120%;
              opacity: 0;
              transition: all 0.8s
          }

          .button:active:after {
              padding: 0;
              margin: 0;
              opacity: 1;
              transition: 0s
          }

        
        </style>

  </head>
  <body>

     
     <section class="top-header">
      <a href="portada.php">
      <img src="images/logo.png" alt="Social Network UGR">
      <h1 class="header-letters" id="header-with-transition"> Social Network UGR </h1>
      </a>
      <?php $usuario = $_SESSION['username']; $user_profile = "usuario.php?usuario=" . $_SESSION['username']; ?>
      <a href="<?php echo $user_profile ?>">
      <b class="username"> <?php echo $_SESSION['username'] ?> </b>
       <img class="user-image" src= "<?php echo $_SESSION['foto_usuario'] ?>" alt="Social Network UGR">
      </a>
      <a href="conexiones/salir.php" class="back-to-index"> Bye, Bye... </a>
    </section>
    <section class="portada-menu">
      <nav> <a href="<?php echo 'usuario.php?usuario=' . $_GET['usuario']  ?>"> Biografía </a> - <a href="fotos.php"> Fotos </a> - <a href="<?php echo 'info.php?usuario=' . $_GET['usuario']  ?>"> Información personal </a> </nav>
      <hr>
    </section>

    
    <section class="friends-menu">
      <section class="main">

      <?php 
        $sql  = "SELECT usuarios.username, usuarios.foto_usuario, entradas.username, entradas.fecha_public FROM entradas, usuarios WHERE usuarios.username = entradas.username GROUP BY entradas.username HAVING entradas.fecha_public >= CURDATE()-10 ORDER by count(*) DESC;";
        $result = $conn->query($sql);
        $array = $result->fetchAll(PDO::FETCH_ASSOC);     


        foreach ($array as $muro_fama) {
           $nombre_f = $muro_fama['username'];
           $foto_f = $muro_fama['foto_usuario'];
           $user_dir = "usuario.php?usuario=" . "$nombre_f";
            
              $sql = "SELECT titulo FROM entradas WHERE username = '$nombre_f';";
                $result = $conn->query($sql);
                $valores = $result->fetchAll(PDO::FETCH_ASSOC);  

              $info = "ENTRADAS PUBLICADAS: - ";
              foreach ($valores as $titulos){
                $info .= $titulos['titulo'];
                $info .= " - "; 
              } 


            echo "
            <section id=\"column\">
            <a href=" . $user_dir . " id=\"get_content\" title='" . $info . "'>
              <section id=\"user-name\"> <h3> " . $nombre_f . " </h3> </section>
              <img id=\"user-picture\" src=" . $foto_f . " alt=\"user-picture\">
            </a>
            </section>";

        }



       ?>

     </section>
    </section>

    <section class="recent-users">
    <button type="button" class="button" id="usuarios_activos"> USUARIOS ACTIVOS </button>
      

      <section id="recent-users-profiles">
         <?php
          $sql  = "SELECT username, foto_usuario FROM usuarios WHERE activo = 1;";
           $result = $conn->query($sql);
           $array = $result->fetchAll(PDO::FETCH_ASSOC);   

        foreach ($array as $recent) {
              $nombre_r = $recent['username'];
              $foto_r = $recent['foto_usuario'];
              $user_dir = "usuario.php?usuario=" . "$nombre_r";
              
              
              $sql = "SELECT titulo FROM entradas WHERE username = '$nombre_r';";
                $result = $conn->query($sql);
                $valores = $result->fetchAll(PDO::FETCH_ASSOC);  

              $info = "ENTRADAS PUBLICADAS: - ";
              foreach ($valores as $titulos){
                $info .= $titulos['titulo'];
                $info .= " - "; 
              }

              echo  "
                  <a href=" . $user_dir . " id=\"get_content\" title='" . $info . "'>
                    <section id=\"recent-user-name\"> <h5> " . $nombre_r . "  </h5> </section>
                    <img id=\"recent-user-picture\" src=" . $foto_r . " alt=\"user-picture\">
                  </a>";

        }


      ?>
        
      </section>
    </section>
    <section class="entradas">

    <?php
         if($_SESSION['username'] == $_GET['usuario']){ // Pagina del usuario actual
            $usuario_pag = $_SESSION['username'];
            
            echo "<section class=\"personal-info\">
                <img src=" . $_SESSION['foto_usuario'] . " id=\"foto_us\">
                <br>
                <section id=\"activo\">
                    <strong> Activo desde:  </strong> " . $_SESSION['fecha_registro'] . " <strong> Ultima conexion: </strong>" . $_SESSION['last_login'] . "
                </section>
                <section class=\"info-us-act\">
                    <form id=\"info_per\" action=\"conexiones/cambiar_info.php\" method=\"post\">
                        <strong> Nombre:  &nbsp;&nbsp;</strong>" . $_SESSION['nombre'] . " &nbsp;&nbsp;&nbsp;
                        <input type=\"text\" name=\"nombre\" placeholder=\"Inserta un nuevo nombre\"><br>

                        <strong> Apellidos:  &nbsp;&nbsp;</strong>" . $_SESSION['apellidos'] . " &nbsp;&nbsp;&nbsp;
                        <input type=\"text\" name=\"apellidos\" placeholder=\"Inserta nuevos apellidos\"><br>

                        <strong> Nombre de usuario: &nbsp;&nbsp;</strong>" . $_SESSION['username'] . " &nbsp;&nbsp;&nbsp;
                        <input type=\"text\" name=\"username\" placeholder=\"Inserta un nuevo nombre de usuario\"><br>

                        <strong> Email:  &nbsp;&nbsp;</strong>" . $_SESSION['email'] . " &nbsp;&nbsp;&nbsp;
                        <input type=\"text\" name=\"email\" placeholder=\"Inserta nuevo email\"><br>

                        <br>
                        <input type=\"submit\" value=\"Guardar Cambios\" name=\"GuardarCambios\" onclick=\"return guardar_cambios(this);\">
                        <br>
                        <br>
                        <br>
                        <br>
                        <br>
                        <br>
                        <br>
                        <br>
                    </form>

                    <form id=\"borrar_usuario\" action=\"conexiones/borrar_usuario.php\" method=\"POST\">
                      <input type=\"submit\" name=\"submit\" value=\"Borrar usuario\" onclick=\"return borrar_usuario(this);\">
                    </form>

                    <form id=\"cambiar_foto\" enctype=\"multipart/form-data\" action=\"conexiones/cambiar_foto.php\" method=\"POST\">
                      <input type=\"hidden\" name=\"MAX_FILE_SIZE\" value=\"100000000000000\" />
                      <strong> Seleccionar nueva foto: </strong> <input name=\"userfile\" type=\"file\" />
                      <input type=\"submit\" value=\"Cambiar foto\" />
                    </form>
                </section>
            </section>
            ";
             
         }else{ // Pagina de otro usuario, cargamos sus respectivas entradas
         
              $usuario_pag = $_GET['usuario'];

              
              $sql = "SELECT nombre, apellidos, username, foto_usuario, fecha_registro, last_login FROM usuarios WHERE username = '$usuario_pag';";
               $result = $conn->query($sql);
               $array = $result->fetchAll(PDO::FETCH_ASSOC);
               
               $nombre = $array[0]['nombre'];
               $apellidos = $array[0]['apellidos'];
               $username = $array[0]['username'];
               $foto_usuario = $array[0]['foto_usuario'];
               $fecha_registro = $array[0]['fecha_registro'];
               $last_login = $array[0]['last_login'];
               

                  echo "<section class=\"personal-info\">
                <img src=" . $foto_usuario . " id=\"foto_us\">
                <br>
                <section id=\"activo\">
                    <strong> Activo desde:  </strong> " . $fecha_registro . " <strong> Ultima conexion: </strong>" . $last_login . "
                </section>
                <section id=\"info-us\">
                        <strong> Nombre:  &nbsp;&nbsp;</strong>" . $nombre . " &nbsp;&nbsp;&nbsp; <br>
                        <strong> Apellidos:  &nbsp;&nbsp;</strong>" . $apellidos . " &nbsp;&nbsp;&nbsp; <br>
                        <strong> Nombre de usuario: &nbsp;&nbsp;</strong>" . $username . " &nbsp;&nbsp;&nbsp; <br>
                </section>
            </section>

              <form id=\"amigo\" action=\"conexiones/amistad.php\" method=\"post\">
                  <input type=\"hidden\" class=\"titulo\" id=\"El titulo\" value=" . $username .  " name=\"username\" required>
                  <input type=\"submit\" name=\"AgregarAmigo\" value=\"Agregar Amigo\" onclick=\"return amistad(this);\">
              </form>
            ";


               
           }
      
    ?>
     <script>

          $(document).ready(function() {
              $("#usuarios_activos").click(function(){
                  $.ajax({
                        url: 'conexiones/usuarios_activos.php',
                        data: "",
                        dataType: 'json',
                        success: function(data){
                                    $("#recent-users-profiles").html(
                                      "<section></section>"
                                    );
                                    for(var usuario in data){
                                      var name = data[usuario]['username'];
                                      var pic = data[usuario]['foto_usuario'];
                                      var user_dir = "usuario.php?usuario=" + name;

                                      $("#recent-users-profiles").append(

                                          "<a href=" + user_dir + " >" +
                                              "<section id=" + "parent" + ">" +
                                              "<section id=" + "recent-user-name" + "> <h5> " + name + "  </h5> </section>" +
                                              "<img id=" + "recent-user-picture " + "src=" +  pic + " alt=" + "user-picture" + ">" +
                                              "<p id=" + "popup" +  "style=" + "display: none" + "> </p>" +
                                              "</section>" +
                                            "</a>"

                                      );
                                    }
                                 }
                  });    
              });            
            });

          $(document).ready(function () {
            $("#get_content").hover(function (){
                $('usuario').qtip();
            });
            
        });
      </script>
    </section> 
     <section class="bottom-sections">
      <hr>
      <footer class="about"> <a href="red-social/contacto.php"> Contacto </a> - <a href="../red-social/como_se_hizo.pdf"> Cómo se hizo </a> </footer>

      </section>
  </body>
</html>
