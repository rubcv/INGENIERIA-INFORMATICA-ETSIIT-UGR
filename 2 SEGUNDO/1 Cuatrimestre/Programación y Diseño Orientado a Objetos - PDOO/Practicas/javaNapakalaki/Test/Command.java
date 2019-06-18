
package Test;

public enum Command {
  Exit (0, "Salir del juego"),
  GoBack (-1, "Menu anterior"), 
  Combat (69, "¡¡ C O M B A T I R !!"),
  ShowMonster         (10, "Mostrar monstruo"), 
  ShowVisibleTreasure (11, "Mostrar tesoros visibles"), 
  ShowHiddenTreasure  (12, "Mostrar tesoros ocultos"), 
  DiscardVisibleTreasure (21, "Descartar tesoro visible"), 
  DiscardHiddenTreasure  (22, "Descartar tesoro oculto"), 
  DiscardAll             (23, "Descartar TODOS los tesoros"),
  MakeTreasureVisible    (31, "Equipar tesoro"), 
  StealTreasure    (32, "Robar tesoro"),
  NextTurn         (1, "Siguiente turno"),
  NextTurnAllowed  (2, "Siguiente turno permitido");
  
  public final int menu;
  public final String text;
  
  private Command (int aValue, String aText) {
    this.menu = aValue;
    this.text = aText;
  }
}
