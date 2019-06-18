class Barberia extends AbstractMonitor {
  private Condition salaEspera = makeCondition();
  private Condition silla = makeCondition();
  private Condition barbero = makeCondition();

  public void cortarPelo() {
    enter();
    if(!barbero.isEmpty()) { // Si no esta ocupado, lo aviso
      barbero.signal();
    }
    else {
      salaEspera.await(); // Si esta ocupado, lo espero
    }
    silla.await(); // En cualquier caso, se ocupa la silla
    leave();
  }

  public void siguienteCliente() {
    enter();
    if(!salaEspera.isEmpty()) { // Si esta ocupado va a la sala de espera
      salaEspera.signal();
    }
    else {
      barbero.await(); // Ocupa al barbero
    }
    leave();
  }

  public void finCliente() {
    enter();
    silla.signal(); // La silla se vacia
    leave();
  }
}
