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
      #entrada-box h5{
        word-wrap: break-word;
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

              $sql = "SELECT foto_usuario, username FROM usuarios WHERE username = '$usuario_pag';";
              $conn->query($sql);
                $result = $conn->query($sql);
                $array = $result->fetchAll(PDO::FETCH_ASSOC); 
                
                $nombre_e = $array[0]['username'];
                $foto_e = $array[0]['foto_usuario'];
                $user_dir = "usuario.php?usuario=" . "$nombre_e";
              

                  echo "  <a href=" . $user_dir . ">
                              <section class=\"entry-user-name2\"> <h4>" . $nombre_e . " </h4> </section>
                              <img id=\"recent-user-picture2\" src=" . $foto_e . " alt=\"user-picture\">
                          </a>
                          <br>
                          <section class=\"entrada-nueva\" id=\"nueva-entrada-box\">
                              <section class=\"entrada-input\">
                              <form class=\"nueva_entrada\" action=\"conexiones/subir_entrada.php\" method=\"post\">
                                <input type=\"text\" class=\"titulo\" id=\"El titulo\" placeholder=\"Introduce aqui el titulo de la entrada\" name=\"titulo\" required>
                                <br>
                                <textarea class=\"wideInput\" id=\"El texto\" placeholder=\"Introduce aqui la entrada\" name=\"texto\" required></textarea>
                                
                                </section>
                                <br>
                                <section class=\"entrada-buttons\">
                                    <input type=\"submit\"  value=\"Enviar\" class=\"enviar\" name=\"SubmitButton\"  onclick=\"return confirmacion(this);\">
                                </form>
                                </section>
                            </section>";

              $sql  = "SELECT usuarios.foto_usuario, entradas.username, usuarios.username, entradas.titulo, entradas.id_ent, entradas.texto, entradas.fecha_public FROM entradas, usuarios WHERE usuarios.username = '$usuario_pag' AND usuarios.username = entradas.username ORDER BY entradas.id_ent DESC;";
                $result = $conn->query($sql);
                $array = $result->fetchAll(PDO::FETCH_ASSOC); 
  
                
            foreach ($array as $entrada) {
                $nombre_e = $entrada['username'];
                $foto_e = $entrada['foto_usuario'];
                $titulo_e = $entrada['titulo'];
                $fecha_e = $entrada['fecha_public'];
                $texto_e = $entrada['texto'];
                $entrada_id = $entrada['id_ent'];
                $user_dir = "usuario.php?usuario=" . "$nombre_e";
                $entrada_dir = "entrada.php?entrada=" . $entrada_id;
                
                if (strlen($texto_e) > 150)
                    $texto_e = substr($texto_e, 0, 147) . '...';

                $sql = "SELECT titulo FROM entradas WHERE username = '$nombre_e';";
                    $result = $conn->query($sql);
                    $valores = $result->fetchAll(PDO::FETCH_ASSOC);  

                  $info = "ENTRADAS PUBLICADAS: - ";
                  foreach ($valores as $titulos){
                    $info .= $titulos['titulo'];
                    $info .= " - "; 
                  } 

                echo "
                <section class=\"entrada\" id=\"entrada-box\">
                  <sup>" . "$fecha_e" . " </sup>
                   <a href=" . $user_dir . " id=\"get_content\" title='" . $info . "'>
                    <section id=\"entry-user-name\"> <h4>" . $nombre_e . " </h4> </section>
                    <img id=\"recent-user-picture\" src=" . $foto_e . " alt=\"user-picture\">
                  </a>
                    <a href=". $entrada_dir . ">
                    <h3>  " . "$titulo_e" . " </h3>
                    <h5>" . "$texto_e" . "
                    </h5>
                    </a>
                  </section>
                ";

            }
          
         }else{ // Pagina de otro usuario, cargamos sus respectivas entradas
         
              $usuario_pag = $_GET['usuario'];
                $sql  = "SELECT usuarios.foto_usuario, entradas.username, usuarios.username, entradas.titulo, entradas.id_ent, entradas.texto, entradas.fecha_public FROM entradas, usuarios WHERE usuarios.username = '$usuario_pag' AND usuarios.username = entradas.username ORDER BY entradas.id_ent DESC;";
                $result = $conn->query($sql);
              $array = $result->fetchAll(PDO::FETCH_ASSOC); 

            
              foreach ($array as $entrada) {
                  $nombre_e = $entrada['username'];
                  $foto_e = $entrada['foto_usuario'];
                  $titulo_e = $entrada['titulo'];
                  $fecha_e = $entrada['fecha_public'];
                  $texto_e = $entrada['texto'];
                  $entrada_id = $entrada['id_ent'];
                  $user_dir = "usuario.php?usuario=" . "$nombre_e";
                  $entrada_dir = "entrada.php?entrada=" . $entrada_id;
                  
                  
                  if (strlen($texto_e) > 150)
                      $texto_e = substr($texto_e, 0, 147) . '...';

                  $sql = "SELECT titulo FROM entradas WHERE username = '$nombre_e';";
                    $result = $conn->query($sql);
                    $valores = $result->fetchAll(PDO::FETCH_ASSOC);  

                  $info = "ENTRADAS PUBLICADAS: - ";
                  foreach ($valores as $titulos){
                    $info .= $titulos['titulo'];
                    $info .= " - "; 
                  } 

                  echo "
                  <section class=\"entrada1\" id=\"entrada-box\">
                    <sup>" . "$fecha_e" . " </sup>
                     <a href=" . $user_dir . " id=\"get_content\" title='" . $info . "'>
                    <section id=\"entry-user-name\"> <h4>" . $nombre_e . " </h4> </section>
                      <img id=\"recent-user-picture\" src=" . $foto_e . " alt=\"user-picture\">
                      </a>
                       <a href=". $entrada_dir . ">
                      <h3>  " . "$titulo_e" . " <a> </h3>
                      <h5>" . "$texto_e" . "
                      </h5>
                      </a>
                    </section>
                  ";

              }
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
