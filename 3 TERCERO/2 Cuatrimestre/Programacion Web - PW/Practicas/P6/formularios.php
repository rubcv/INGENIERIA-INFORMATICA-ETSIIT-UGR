<!-- CLASE CALCULADORA -->
<!DOCTYPE html>
<html>

    <h1> Calculadora simple </h1>
    <body>
    <?php
        
        class Formularios {
            private $_formularios = [];

            function __set($id, $text){
                $this->_formularios[$id] = $text;
            }

            public function print_form($id){

            }

        }
    ?>
    </body>

</html>