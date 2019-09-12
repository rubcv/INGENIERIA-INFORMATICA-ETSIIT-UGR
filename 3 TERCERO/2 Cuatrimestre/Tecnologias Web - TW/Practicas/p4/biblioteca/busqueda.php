<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
        <title>Busqueda de libro</title>
</head>
    <body>

        <?php

            if(isset($_GET['titulo'])){

                echo "<h1> Resultados para " . $_GET['titulo'] . "</h1> <br>";
                $titulo = $_GET['titulo'];   
                $titulo = urldecode($titulo);

                $cadena = 'http://bencore.ugr.es/iii/encore/search?formids=target&lang=spi&suite=def&reservedids=lang%2Csuite&submitmode=&submitname=&target=' . $titulo . '&submit.x=0&submit.y=0';
                

                $curl = curl_init();

                
                curl_setopt($curl, CURLOPT_URL, $cadena);

                curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);

                curl_setopt($curl, CURLOPT_USERAGENT, 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.13) Gecko/20080311 Firefox/2.0.0.13');
                        

                $resultado = curl_exec($curl);
                
                $expresion = "/<span class=\"title\">[^<]*<a[^>]*>[^<]*<\/a><\/span>/";
                $salida1 = "";
                $salida2 = "";
                preg_match_all($expresion, $resultado, $salida1);
                
             


                $expresion = "/<span class=\"title\">.*<\/span>/";
                
                preg_match_all($expresion, $resultado, $salida2);
                

                for ($i=0; $i < sizeof($salida1[0]); $i++) { 
                   echo "<strong> Nombre: </strong>" . $salida1[0][$i] . " <strong>Autor: </strong>" . $salida2[0][$i] . "<br><br>";
                }

                curl_close($curl);
                        

                
              

            }

        ?> 
    
    </body>

</html>

