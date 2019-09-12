<!-- CLASE CALCULADORA -->
<!DOCTYPE html>
<html>
    <body>
    <?php
 
        class Calculadora {
            private $_num1 = 1;
            protected $_num2 = 1;


        function Calculadora($n1, $n2){
            $this->_num1 = $n1;
            $this->_num2 = $n2;
        }
        public function suma(){
            return $this->_num1 + $this->_num2;
        }

        public function resta(){
            return $this->_num1 - $this->_num2;
        } 

        public function multiplicacion(){
            return $this->_num1 * $this->_num2;
        }

        public function division(){
            return $this->_num1 / $this->_num2;
        }

        }


    ?>
    </body>

</html>