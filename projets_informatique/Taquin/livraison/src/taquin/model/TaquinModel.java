package taquin.model;

import taquin.util.AbstractModeleEcoutable;

/**
 * Modèle de jeu du Taquin
 *
 */
public class TaquinModel extends AbstractModeleEcoutable {

	private int[][] board;
	private int height;
	private int width;
	private int nombreCoupsJoues = 0;
	private boolean gameLauch;
	private boolean help;
	public static final int DEFAULT_COMPLEXITY = 3;

	/**
	 * Constructeur de Taquin, jeu de taille n * m en paramètre. Mélange automatique
	 * des éléments avec complexité par défaut.
	 * 
	 * @param height
	 * @param width
	 */
	public TaquinModel(int height, int width) {
		super();
		assert height > 2 && height < 20 && width > 2 && width < 20 : "Height or witdh < 2 or > 10";
		board = new int[height][width];
		this.height = height;
		this.width = width;
		this.gameLauch = true;
		this.help = false;
		shuffleElements(DEFAULT_COMPLEXITY);
	}

	/**
	 * Place les élements dans le plateau de jeu terminé.
	 */
	public void placeElementsFinish() {
		int index = 1;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (index == height * width)
					index = 0;
				board[i][j] = index++;
			}
		}
		notifyChangement();
	}

	/**
	 * Affichage en console de l'état du plateau de jeu.
	 */
	public void printBoard() {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				System.out.print("|" + board[i][j] + "|");
			}
			System.out.println();
		}
	}

	/**
	 * Un puzzle ordonné est la suite des entiers croissants avec la case vide en
	 * bas à droite.
	 * 
	 * @return Vrai si le jeu est terminé
	 */
	public boolean isFinished() {
		int cpt = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (board[i][j] > cpt) {
					cpt = board[i][j];
				} else if (!(board[i][j] == 0 && i == height - 1 && j == width - 1)) {
					return false;
				}
			}
		}
		return true;
	}

	/**
	 * Indique s'il est possible de bouger une case dans la direction donnée, càd si
	 * la case adjacente est libre (0).
	 * 
	 * @param i Index x de la case de départ
	 * @param j Index y de la case de départ
	 * @param d Direction du déplacement
	 * @return Vrai si le mouvement est possible
	 */
	public boolean isPossibleToMove(int i, int j, Direction d) {
		switch (d) {
		case NORD:
			return !(i == 0 || board[i - 1][j] != 0);
		case SUD:
			return !(i == height - 1 || board[i + 1][j] != 0);
		case OUEST:
			return !(j == 0 || board[i][j - 1] != 0);
		case EST:
			return !(j == width - 1 || board[i][j + 1] != 0);
		}
		return false;
	}

	/**
	 * Indique si une case peut se déplacer dans une des quatre directions possible
	 * 
	 * @param number Le numéro de la case concernée
	 * @return Vrai si elle peut se déplacer dans une des quatres directions
	 *         possible
	 */
	public boolean isPossibleToMove(int number) {
		int indexi = 0;
		int indexj = 0;
		outerloop: for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (board[i][j] == number) {
					indexi = i;
					indexj = j;
					break outerloop;
				}
			}
		}
		for (Direction d : Direction.values()) {
			if (isPossibleToMove(indexi, indexj, d)) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Indique si un mouvement est possible dans la direction donnée.
	 * 
	 * @param d Direction du mouvement.
	 * @return Vrai si un mouvement est possible
	 */
	public boolean isPossibleToMove(Direction d) {
		int indexIVide = 0;
		int indexJVide = 0;
		outerloop: for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (board[i][j] == 0) {
					indexIVide = i;
					indexJVide = j;
					break outerloop;
				}
			}
		}
		switch (d) {
		case NORD:
			if (indexIVide + 1 < height && isPossibleToMove(indexIVide + 1, indexJVide, Direction.NORD))
				return isPossibleToMove(indexIVide + 1, indexJVide, Direction.NORD);
			break;
		case SUD:
			if (indexIVide - 1 >= 0 && isPossibleToMove(indexIVide - 1, indexJVide, Direction.SUD))
				return isPossibleToMove(indexIVide - 1, indexJVide, Direction.SUD);
			break;
		case EST:
			if (indexJVide - 1 >= 0 && isPossibleToMove(indexIVide, indexJVide - 1, Direction.EST))
				return isPossibleToMove(indexIVide, indexJVide - 1, Direction.EST);
			break;
		case OUEST:
			if (indexJVide + 1 < width && isPossibleToMove(indexIVide, indexJVide + 1, Direction.OUEST))
				return isPossibleToMove(indexIVide, indexJVide + 1, Direction.OUEST);
			break;
		}
		return false;
	}

	/**
	 * Joue un coup sur le plateau de jeu avec la position de la case et une
	 * direction
	 * 
	 * @param i Index x de la case de départ
	 * @param j Index y de la case de départ
	 * @param d Direction du déplacement
	 */
	public void play(int i, int j, Direction d) {
		if (isPossibleToMove(i, j, d)) {
			switch (d) {
			case NORD:
				board[i - 1][j] = board[i][j];
				board[i][j] = 0;
				break;
			case SUD:
				board[i + 1][j] = board[i][j];
				board[i][j] = 0;
				break;
			case OUEST:
				board[i][j - 1] = board[i][j];
				board[i][j] = 0;
				break;
			case EST:
				board[i][j + 1] = board[i][j];
				board[i][j] = 0;
				break;
			}
		}
		nombreCoupsJoues++;
		notifyChangement();
	}

	/**
	 * Joue un coup sur le plateau de jeu en fonction du numéro de la case donnée.
	 * Si aucun coup n'est possible avec cette case, le plateau reste inchangé.
	 * 
	 * @param number Le numéro de la case
	 */
	public void play(int number) {
		int indexi = 0;
		int indexj = 0;
		outerloop: for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (board[i][j] == number) {
					indexi = i;
					indexj = j;
					break outerloop;
				}
			}
		}
		for (Direction d : Direction.values()) {
			if (isPossibleToMove(indexi, indexj, d)) {
				play(indexi, indexj, d);
				break;
			}
		}
	}

	/**
	 * Joue un coup sur le plateau de jeu dans la direction donnée si c'est
	 * possible.
	 * 
	 * @param d Direction du mouvement demandé
	 */
	public void play(Direction d) {
		int indexIVide = 0;
		int indexJVide = 0;
		outerloop: for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (board[i][j] == 0) {
					indexIVide = i;
					indexJVide = j;
					break outerloop;
				}
			}
		}
		switch (d) {
		case NORD:
			if (indexIVide + 1 < height && isPossibleToMove(indexIVide + 1, indexJVide, Direction.NORD))
				play(indexIVide + 1, indexJVide, Direction.NORD);
			break;
		case SUD:
			if (indexIVide - 1 >= 0 && isPossibleToMove(indexIVide - 1, indexJVide, Direction.SUD))
				play(indexIVide - 1, indexJVide, Direction.SUD);
			break;
		case EST:
			if (indexJVide - 1 >= 0 && isPossibleToMove(indexIVide, indexJVide - 1, Direction.EST))
				play(indexIVide, indexJVide - 1, Direction.EST);
			break;
		case OUEST:
			if (indexJVide + 1 < width && isPossibleToMove(indexIVide, indexJVide + 1, Direction.OUEST))
				play(indexIVide, indexJVide + 1, Direction.OUEST);
			break;
		}
	}

	/**
	 * Mélange des éléments du plateau. Le plateau est toujours réalisable car il
	 * part de la solution finale en effectuant des permutations. La complexité
	 * donnée est le nombre de mouvements faits aléatoirement sur le plateau de jeu.
	 * 
	 * @param complexity Nombre de mouvements effectués sur le plateau, c'est en
	 *                   quelque sorte le niveau du jeu.
	 */
	public void shuffleElements(int complexity) {
		gameLauch = false;
		placeElementsFinish();
		Direction oldDir = null;
		for (int i = 0; i < complexity; i++) {
			Direction dir = Direction.getRandomDirection();
			if (dir == oldDir)
				i--;
			else {
				if (isPossibleToMove(dir)) {
					play(dir);
					oldDir = Direction.oppositeDir(dir);
				} else
					i--;
			}
		}
		resetNombreCoupsJoues();
	}

	/**
	 * Retourne le contenu de la case aux coordonnées x et y
	 * 
	 * @param x Coordonnées x de la case
	 * @param y Coordonnées y de la case
	 * @return Contenu de la case aux coordonnées x et y
	 */
	public int getCase(int x, int y) {
		return board[x][y];
	}

	public int[][] getBoard() {
		return board;
	}

	public int getWidth() {
		return width;
	}

	public int getHeight() {
		return height;
	}

	public int getNombreCoupsJoues() {
		return nombreCoupsJoues;
	}

	public boolean isGameLauch() {
		return gameLauch;
	}

	/**
	 * Met à 0 le nombre de coups joués. La partie est relancée.
	 */
	public void resetNombreCoupsJoues() {
		nombreCoupsJoues = 0;
		gameLauch = true;
		notifyChangement();
	}

	public boolean getHelp() {
		return help;
	}

	/**
	 * Met à jour la variable de demande d'aide
	 * 
	 * @param b Demande d'aide dans le jeu
	 */
	public void requestHelp(boolean b) {
		help = b;
		notifyChangement();
	}
}
