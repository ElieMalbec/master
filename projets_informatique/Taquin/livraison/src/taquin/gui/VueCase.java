package taquin.gui;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;

import taquin.model.TaquinModel;

/**
 * Vue sur une case du plateau de Jeu. Représente son contenu sous forme d'une
 * partie d'image et d'un entier si aide demandée. Les cases sont mises à jour
 * sur demande de la vue du Taquin.
 */
public class VueCase extends JPanel {

	private static final long serialVersionUID = 1L;
	/** Contenu de la case, l'entier qui la représente */
	private int contentCase;
	public static Dimension DIM_CASE = new Dimension(70, 70);
	/** Référence sur le modèle */
	private TaquinModel modele;
	/** Liste des images du jeu */
	private ArrayList<BufferedImage> images;

	/** Indique si la case peut être bougée */
	private boolean isPossibleToMove = false;
	/** Affiche le numéro de la case si activé */
	private JLabel debug;

	/**
	 * Constructeur d'une vue sur une Case.
	 * 
	 * @param modele Modèle de référence
	 * @param x      Position x dans le plateau de jeu
	 * @param y      Position y dans le plateau de jeu
	 * @param images Liste d'images
	 */
	public VueCase(TaquinModel modele, int x, int y, ArrayList<BufferedImage> images) {
		this.modele = modele;
		this.images = images;
		this.contentCase = modele.getCase(x, y);
		this.setPreferredSize(DIM_CASE);
		this.debug = new JLabel(String.valueOf(contentCase));
		this.debug.setHorizontalAlignment(SwingConstants.CENTER);
		this.debug.setFont(new Font("Ubuntu", Font.BOLD, 20));
		this.add(debug);
	}

	/**
	 * Mise à jour de la case avec un nouveau contenu, elle se repaint par la suite.
	 * Le contenu de la case est associé à une image dans la liste d'image.
	 * 
	 * @param number Nouveau contenu de la case associé à une image
	 */
	public void updateCase(int number) {
		contentCase = number;
		repaint();
	}

	/**
	 * Survol de la vue sur la Case, si la case peut bouger, elle s'affiche avec un
	 * cadre de couleur.
	 */
	public void survol() {
		isPossibleToMove = (modele.isPossibleToMove(contentCase) && !modele.isFinished());
		repaint();
	}

	/**
	 * Ajoute les éléments graphiques sur la Vue. Une partie de l'image associée au
	 * contenu de la case est affiché. Si le debut est activé, le numéro de case est
	 * affiché. Si la case est survolé et qu'il est possible de la bouger, un cadre
	 * de couleur apparaît pour le signaler.
	 */
	@Override
	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;
		super.paintComponent(g2);
		if (modele.getHelp())
			debug.setText(String.valueOf(contentCase));
		else
			debug.setText("");
		if (contentCase != 0) {
			g2.drawImage(images.get(contentCase - 1), 0, 0, getWidth(), getHeight(), this);
			if (isPossibleToMove) {
				g2.setStroke(new BasicStroke(5.0f));
				g2.setColor(new Color(16711935));
				g2.drawRect(0, 0, getWidth() - 1, getHeight() - 1);
			}
		}
	}

	public int getContent() {
		return contentCase;
	}

	/**
	 * Met à jour si la case peut bouger dans le plateau de jeu.
	 * @param b
	 */
	public void setIsPossibleToMove(boolean b) {
		isPossibleToMove = b;
		repaint();
	}
	
	public void setImages(ArrayList<BufferedImage> images) {
		this.images = images;
	}
}
