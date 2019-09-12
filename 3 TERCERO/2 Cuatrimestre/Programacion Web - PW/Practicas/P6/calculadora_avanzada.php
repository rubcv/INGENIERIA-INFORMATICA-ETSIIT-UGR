<!-- CLASE CALCULADORA -->
<!DOCTYPE html>
<html>

    <h1> Calculadora simple </h1>
    <body>
    <?php
        
       
        require_once("calculadora.php");
        class CalculadoraAvanzada extends Calculadora {
            private $_num1 = 1;

            function CalculadoraAvanzada($n1){
                $this->_num1 = $n1;

            }  

           public function raiz(){
               return sqrt($this->_num1);
           }  
        
           public function potencia($exp){
               return pow($this->_num1, $exp);
           }

           public function exponencial(){
               return exp($this->_num1);
           }

        }


        $una = new Calculadora(1, 2);
        $otra = new CalculadoraAvanzada(5);

        echo "SUMA: " . $una->suma() . "\n";
        echo "POTENCIA: " . $otra->potencia(2);
 
        echo "\nCalculadora\n\n";
    ?>
    </body>

</html>