<!DOCTYPE html>
<html lang="es">
  <head>
    <link rel="stylesheet" href="css/entrada-style.css">
    <meta charset="utf-8">
    <title>Usuario: Social Network UGR </title>
    <script src="https://code.jquery.com/jquery-3.2.1.js"> </script>

    <script src="js/include.js"></script>
    <?php
            include("conexiones/sesion.php"); 
            
            if (!isset($_SESSION["username"])){
                    header("location: index.php");
            }

            function parsearMedia($media){
                return $media != "" && $media != null;
            }

            function setVideoOFoto($media){ // 1 si es foto, 2 si es video de youtube
                if(strpos($media, 'youtube') !== false){
                    return 2;
                }
              
              return 1;
            }

    ?>
    <style>
        body {
            margin: 0;
            font-family: 'Lato', sans-serif;
        }
         .recent-users {
          overflow-y:scroll;
          z-index: 0.5;
        }
        .entradas{
          width: 1210px;
          overflow-y:scroll;
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
        #entry-text{
            font-size: 14px;
           margin-top: 80px;
            text-align: left;
            word-wrap: break-word;
           
        }
        #entrada-box{
            height: 500px;
        }
        #entry-tittle{
            margin-bottom: 20px;
            margin-left: 20px;
            margin-top: 115px;
            font-size: 1.1em;
            float: left;
        }
        #entry-img{
            margin-top: 30px;
            margin-left: 600px;
            border-style: dashed;
        }
        #entry-user-picture{
            margin-right: -900px;
            margin-top: -10px;
            padding-top: 5px;
        }
        #entry-user-name{
            margin-right: -900px;
        }
        .wideInput{
            width: 800px;
            height: 100px;
            margin-left: 150px;
        }
        .enviar{
            height: 50px;
            width: 70%;
            margin-left: -90px;
            margin-top: 100px;
            margin-bottom: -30px;
        }
        #comentario-box{
            height: 400px;
            margin-top: 30px;
        }
        #act-comentario-box{
            height: 200px;
        }
        #zona-comentarios{
            padding-top: 30px;
            border-color: green;
            border-style: dashed;
            margin-top: 60px;
            margin-left: 0px;
             overflow-y:scroll;
             height: 400px;
             width: 100%;
        }
        #comentario-text{
            font-size: 15px;
        }
        .nuevo-user-picture{
            margin-top: 0px;
            margin-right: -270px;
            margin-bottom: 10px;
        }
        .nuevo-user-name{
            margin-right: -1000px;
            font-size: 1.2em;
        }
        .titulo{
            z-index: -10;
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
      <nav> <a href="<?php echo 'usuario.php?usuario=' . $_SESSION['username']  ?>"> Biografía </a> - <a href= "fotos.php" >  Fotos </a> - <a href="<?php echo 'info.php?usuario=' . $_SESSION['username']  ?>"> Información personal </a> </nav>
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
        <section id="entrada-box">

    <?php
        $entrada_id = $_GET['entrada'];

        $sql = "SELECT * FROM entradas WHERE id_ent = '$entrada_id';";
            $result = $conn->query($sql);
            $array = $result->fetchAll(PDO::FETCH_ASSOC);
  
        if(sizeof($array) != 0){
            $username = $array[0]['username'];
            $titulo = $array[0]['titulo'];
            $texto = $array[0]['texto'];
            $media = $array[0]['media_ent'];
            $fecha = $array[0]['fecha_public'];

            $sql = "SELECT * FROM usuarios WHERE username = '$username';";
                $result = $conn->query($sql);
                $info_usuario = $result->fetchAll(PDO::FETCH_ASSOC);

            $user_pic = $info_usuario[0]['foto_usuario'];    
            $user_dir = "usuario.php?usuario=" . $username;

            $tieneMedia = parsearMedia($media);
            $setVideoFoto = setVideoOFoto($media);

            echo "   <sup id=\"entry-time\">" . $fecha . " </sup>
                        <a href=" . $user_dir . ">
                            <section id=\"entry-user-name\"> <h5>" . $username . " </h5> </section>
                            <img id=\"entry-user-picture\" src=" . $user_pic . " alt=\"user-picture\">
                        </a>
                            <h3 id=\"entry-tittle\">" . $titulo . " </h3>
                            <h5 id=\"entry-text\"> 
                                " . $texto . "
                            </h5>
                 ";
             if($tieneMedia){  
                    if($setVideoFoto == 1){  
                        echo "    <img id=\"entry-img\" src=". $media . " alt=\"Entrada\">";
                    }else{
                        echo "
                            
                              <iframe id=\"video\" width=\"354\" height=\"154\" src=" . $media . " frameborder=\"0\" allowfullscreen></iframe>
                             ";
                    }
                    
             }



        }

    ?>
       
       </section>
      
 
          

       <section class="nuevo-comentario" id="act-comentario-box">
        <a href= <?php echo  "usuario.php?usuario=" . $_SESSION['username'] ?>>
        <section class="nuevo-user-name"> <h5> <?php echo $_SESSION['username'] ?> </h5> </section>
          <img class="nuevo-user-picture" src=<?php echo $_SESSION['foto_usuario'] ?> alt="user-picture">
        </a>
            <?php
                $id_ent = $_GET['entrada'];

                $sql = "SELECT username FROM entradas WHERE id_ent = '$id_ent';";
                 $result = $conn->query($sql);
                    $array = $result->fetchAll(PDO::FETCH_ASSOC);
                    
                $autor = $array[0]['username'];
                $user = $_SESSION['username'];

                  $sql = "SELECT actual, amigo FROM amigos WHERE actual = '$user' AND amigo = '$autor' AND amigo != '$user';";
                    $result = $conn->query($sql);
                    $array = $result->fetchAll(PDO::FETCH_ASSOC);
  
                if($autor != $user && sizeof($array) == 0){
                    echo "<h4> Debes ser amigo de este usuario para poder comentar en sus entradas </h4>"; 
                }else{

                        echo   "<form class=\"nueva_entrada\" action=\"conexiones/subir_comentario.php\" method=\"post\">
                                <input type=\"hidden\" class=\"titulo\" id=\"El titulo\" value=" . $id_ent .  " name=\"titulo\" required>
                                <br>
                                <textarea class=\"wideInput\" id=\"El texto\" placeholder=\"Introduce aqui la entrada\" name=\"texto\" required></textarea>
                                
                                </section>
                                <br>
                                <section class=\"entrada-buttons\">
                                    <input type=\"submit\"  value=\"Enviar\" class=\"enviar\" name=\"SubmitButton\"  onclick=\"return confirmacion_comentario(this);\">
                                </form>
                    ";
                
                }
            ?>
            <?php
                $sql = "SELECT comentarios.username, comentarios.texto_com, comentarios.fecha_com, usuarios.foto_usuario FROM comentarios, usuarios WHERE comentarios.id_ent = '$entrada_id' AND comentarios.username = usuarios.username;";
                 $result = $conn->query($sql);
                 $array = $result->fetchAll(PDO::FETCH_ASSOC);
               
             
        if(sizeof($array) != 0){
            echo "<section id=\"zona-comentarios\">";
               foreach ($array as $comentario) {
                    $autor = $comentario['username'];
                    $coment = $comentario['texto_com'];
                    $fecha_com = $comentario['fecha_com'];
                    $foto = $comentario['foto_usuario'];
                    $user_dir = "usuario.php?usuario=" . $autor;

                    echo " <section class=\"comentarios\" id=\"act-comentario-box\">  
                          <sup id=\"comment-time\">" . $fecha_com . " </sup>
                            <a href=". $user_dir . ">
                                <section id=\"comment-user-name\"> <h5>" . $autor . "</h5> </section>
                                <img id=\"comment-user-picture\" src=" . $foto . " alt=\"user-picture\">
                            </a>
                            <h5 id=\"comentario-text\">" 
                                . $coment . 
                            "</h5>
                            </section>
                          ";
               }
            }
                echo " </section>";
            ?>
       </section>      

      <script>

        $(document).ready(function() {
                    $('#play-video').on('click', function(ev) {
                    
                        $("#video")[0].src += "&autoplay=1";
                        ev.preventDefault();
                    
                    });
                    });


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
      <footer class="about"> <a href="red-social/contacto.php"> Contacto </a> - <a href="red-social/como_se_hizo.pdf"> Cómo se hizo </a> </footer>

      </section>
  </body>
</html>
 
 
