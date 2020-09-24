package taquin.gui;

import taquin.model.TaquinModel;

/**
 * Démarrage d'une partie graphique de Taquin, possibilité de jouer avec les
 * flèches mais aussi en cliquant sur les cases à déplacer. La taille du jeu est
 * par défaut de 3*3, mais possible de spécifier une taille personalisé au
 * lancement.
 */
public class StartGUI {

	public static void main(String[] args) {
		TaquinGUI game = null;
		if (args.length != 2) {
			game = new TaquinGUI(3, 3);
		} else {
			game = new TaquinGUI(Integer.valueOf(args[0]), Integer.valueOf(args[1]));
		}
		TaquinModel taquin = game.getTaquin();
		new TaquinGUI(taquin);
	}

}
