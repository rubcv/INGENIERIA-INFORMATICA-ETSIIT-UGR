public Estanco extends AbstractMonitor {
private Condition recogida = makeCondition();
private Condition[] ingredientes = new Condition[3];
private int ingredienteDepositado;
private final int SIN_INGREDIENTE = -1;

public Estanco() {
for (int i = 0; i < 3; i++) {
ingredientes[i] = makeCondition();
}
ingredienteDepositado = SIN_INGREDIENTE;
}

public void ponerIngrediente(int nuevoIngrediente) {
enter();
ingredienteDepositado = nuevoIngrediente;
if(!ingredientes[nuevoIngrediente].isEmpty()) {
ingredientes[nuevoIngrediente].signal();
}
leave();
}

public void esperarRecogida() {
enter();
if(ingredienteDepositado != SIN_INGREDIENTE) {
recogida.await();
}
leave();
}

public void obtenerIngrediente(int ingredienteSolicitado) {
enter();
if(ingredienteDepositado != ingredienteSolicitado) {
ingredientes[ingredienteSolicitado].await();
}
ingredienteDepositado = SIN_INGREDIENTE;
if(!recogida.isEmpty()) {
recogida.signal();
}
leave();
}
}
