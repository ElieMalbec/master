package taquin.gui;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

import taquin.model.Direction;
import taquin.model.TaquinModel;
import taquin.util.EcouteurModele;
import taquin.util.ModeleEcoutable;
import taquin.util.Image;

/**
 * Vue principale sur le jeu de Taquin, écoute sur le modèle. Joue également le
 * rôle de Controlleur avec appui sur les touches et clics sur le jeu.
 */
public class VueTaquin extends JPanel implements EcouteurModele, MouseMotionListener, MouseListener, KeyListener {

	private static final long serialVersionUID = 1L;
	/** Modèle de référence */
	private TaquinModel modele;
	/** Liste de vue sur les Cases */
	private ArrayList<VueCase> cases;
	/** Sous-images du jeu pour les cases */
	private ArrayList<BufferedImage> images;

	/**
	 * Constructeur de la vue sur un Jeu de Taquin. Chargement d'une image pour
	 * afficher le fond de jeu.
	 * 
	 * @param taquin Modèle de référence écouté.
	 */
	public VueTaquin(TaquinModel taquin) {
		this.modele = taquin;
		this.modele.ajoutEcouteur(this);
		GridLayout grid = new GridLayout(modele.getHeight(), modele.getWidth());
		this.setLayout(grid);
		cases = new ArrayList<VueCase>();
		loadImages();
		for (int i = 0; i < modele.getHeight(); i++) {
			for (int j = 0; j < modele.getWidth(); j++) {
				VueCase c = new VueCase(modele, i, j, images);
				cases.add(c);
				this.add(c);
			}
		}
		this.addMouseMotionListener(this);
		this.addMouseListener(this);
		this.addKeyListener(this);
		requestFocusInWindow();
	}

	/**
	 * Chargement de l'image principale et découpage en n*m parties pour les vues
	 * des cases.
	 */
	public void loadImages() {
		File parent = new File("./dist/images/");
		String path = "";
		Random rand = new Random();
		int x = rand.nextInt(parent.list().length);
		for (String s : parent.list()) {
			if (x == 0) {
				path = s;
				break;
			}
			x--;
		}
		BufferedImage mainImage = null;
		try {
			File image = new File("./dist/images/" + path);
			mainImage = ImageIO.read(image);
		} catch (IOException exc) {
			exc.printStackTrace();
		}
		if (mainImage != null) {
			images = Image.decoupeImage(modele.getHeight(), modele.getWidth(), mainImage);
			if (!images.isEmpty())
				VueCase.DIM_CASE = new Dimension(images.get(0).getWidth(), images.get(0).getHeight());
			for (VueCase vc : cases)
				vc.setImages(images);
		}
	}

	@Override
	public void modeleMisAJour(ModeleEcoutable source) {
		requestFocusInWindow();
		int t = 0;
		for (int i = 0; i < modele.getHeight(); i++) {
			for (int j = 0; j < modele.getWidth(); j++) {
				cases.get(t++).updateCase(modele.getCase(i, j));
			}
		}
	}

	public TaquinModel getModele() {
		return modele;
	}

	public ArrayList<BufferedImage> getImages() {
		return images;
	}

	/**
	 * Lors du mouvement de la souris, la case concernée est informée qu'elle est
	 * survolée.
	 */
	@Override
	public void mouseMoved(MouseEvent e) {
		for (VueCase vc : cases)
			vc.setIsPossibleToMove(false);
		cases.get((e.getX() / VueCase.DIM_CASE.width) + (e.getY() / VueCase.DIM_CASE.height) * modele.getWidth())
				.survol();
	}

	/**
	 * Lors du click sur le jeu, le coup est joué si c'est possible pour la case
	 * concernée.
	 */
	@Override
	public void mouseClicked(MouseEvent e) {
		int x = e.getX() / VueCase.DIM_CASE.width;
		int y = e.getY() / VueCase.DIM_CASE.height * modele.getWidth();
		if ((modele.isPossibleToMove(cases.get(x + y).getContent()))) {
			modele.play(cases.get(x + y).getContent());
		}
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {
	}

	/**
	 * Lorsque la souris quitte la fenêtre, les cadres de survol disparraissent.
	 */
	@Override
	public void mouseExited(MouseEvent e) {
		for (VueCase vc : cases)
			vc.setIsPossibleToMove(false);
	}

	@Override
	public void mousePressed(MouseEvent e) {
	}

	@Override
	public void mouseReleased(MouseEvent key) {
	}

	/**
	 * Méthode appelée lors de l'appui sur une touche du clavier. Les 4 directions
	 * des flèches permettent de jouer sur le plateau de jeu.
	 * 
	 * @param key Touche du clavier appuyée
	 */
	@Override
	public void keyPressed(KeyEvent key) {
		for (VueCase vc : cases)
			vc.setIsPossibleToMove(false);
		if (key.getKeyCode() == KeyEvent.VK_LEFT) {
			modele.play(Direction.EST);
		} else if (key.getKeyCode() == KeyEvent.VK_UP) {
			modele.play(Direction.SUD);
		} else if (key.getKeyCode() == KeyEvent.VK_RIGHT) {
			modele.play(Direction.OUEST);
		} else if (key.getKeyCode() == KeyEvent.VK_DOWN) {
			modele.play(Direction.NORD);
		}
	}

	@Override
	public void keyReleased(KeyEvent key) {
	}

	@Override
	public void keyTyped(KeyEvent key) {
	}

	@Override
	public void mouseDragged(MouseEvent arg0) {
	}
}
