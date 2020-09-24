package taquin.gui;

import java.awt.BorderLayout;

import javax.swing.JFrame;
import javax.swing.JPanel;

import taquin.model.TaquinModel;

/**
 * Interface graphique du jeu de Taquin.
 */
public class TaquinGUI extends JFrame {

	private static final long serialVersionUID = 1L;
	/** Modèle du jeu de taquin */
	private TaquinModel taquin;
	/** Conteneur principal */
	private JPanel container = new JPanel();
	/** Vue sur le Taquin */
	private VueTaquin vueTaquin;
	/** Vue sur le Menu du jeu */
	private VueMenu vueMenu;

	/**
	 * Instancie un nouveau jeu de Taquin avec les dimensions données. Ne crée pas
	 * l'interface graphique.
	 * 
	 * @param n Nombre de lignes du jeu
	 * @param m Nombre de colonnes du jeu
	 */
	public TaquinGUI(int n, int m) {
		this.taquin = new TaquinModel(n, m);
	}

	/**
	 * Constructeur de l'interface graphique, prend un jeu de Taquin en paramètre.
	 * 
	 * @param taquin Modèle du jeu de Taquin
	 */
	public TaquinGUI(TaquinModel taquin) {
		this.taquin = taquin;
		this.setTitle("Jeu de Taquin");
		this.setSize(1200, 800);
		this.setLocationRelativeTo(null);
		this.setResizable(false);
		this.setVisible(true);
		this.setContentPane(container);
		container.setLayout(new BorderLayout());
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		vueTaquin = new VueTaquin(taquin);
		vueMenu = new VueMenu(this, taquin);
		container.add(vueTaquin, BorderLayout.NORTH);
		container.add(vueMenu, BorderLayout.SOUTH);
		vueTaquin.requestFocusInWindow();
		this.pack();
	}

	public TaquinModel getTaquin() {
		return taquin;
	}
	
	public VueTaquin getVueTaquin() {
		return vueTaquin;
	}

}
