package taquin.model;

import java.util.Random;

/**
 * Enumération des directions possible dans le jeu de Taquin
 */
public enum Direction {
	NORD, SUD, EST, OUEST;
	
	/**
	 * Retourne une direction aléatoire parmi celles possible
	 * @return random direction of the list
	 */
	public static Direction getRandomDirection() {
		Random random = new Random();
		return values()[random.nextInt(values().length)];
	}

	/**
	 * Reetourne la direction opposée à celle donnée en paramètre
	 * @param dir Direction
	 * @return La direction opposée à celle donnée en paramètre
	 */
	public static Direction oppositeDir(Direction dir) {
		switch (dir) {
		case NORD:
			return SUD;
		case SUD:
			return NORD;
		case EST:
			return OUEST;
		case OUEST:
			return EST;
		default:
			return null;
		}
	}
}
