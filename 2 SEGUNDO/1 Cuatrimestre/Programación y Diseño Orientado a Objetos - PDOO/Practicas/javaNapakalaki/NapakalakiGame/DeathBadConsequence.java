package NapakalakiGame;

/**
 *
 * @author manjaro
 */

public class DeathBadConsequence extends NumericBadConsequence {

    private boolean death;

    public DeathBadConsequence(String text, boolean death) {
        super(text, 0, 0, 0);
        this.death = death;
    }

    @Override
    public boolean isDeath() {
        return death;
    }

}
