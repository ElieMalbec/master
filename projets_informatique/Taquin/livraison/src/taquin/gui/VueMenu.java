package taquin.gui;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

import taquin.model.TaquinModel;
import taquin.util.EcouteurModele;
import taquin.util.ModeleEcoutable;

/**
 * Vue+Controleur sur le menu du jeu de Taquin. Permet d'effectuer des actions
 * comme la création d'un nouveau jeu ou l'affichage de l'aide en partie.
 * Compteur de coups joués dans la partie.
 */
public class VueMenu extends JPanel implements EcouteurModele {

	private static final long serialVersionUID = 1L;
	private static final Font courrier = new Font("Courrier", Font.BOLD, 12);
	/** Modèle du jeu de Taquin */
	private TaquinModel modele;
	/** Label du nombre de coups joués dans la partie */
	private JLabel nombreCoups;
	/** Boutton de remise à zéro du jeu (nouvelle partie) */
	private JButton resetBoard;
	/** Afficher de l'aide du jeu */
	private JButton help;
	/** Champ entrée permettant de sélectionner la difficulté du jeu */
	private JTextField complexity;
	/** Référence de la fenêtre principale */
	private TaquinGUI frame;

	/**
	 * Constructeur de la vue-constroleur sur le Menu. Ajoute un Label du nombre de
	 * coups joués, des bouttons d'actions sur le jeu.
	 * 
	 * @param frame  Référence de la fenêtre principale
	 * @param modele Modèle du jeu de Taquin écouté
	 */
	public VueMenu(TaquinGUI frame, TaquinModel modele) {
		this.frame = frame;
		this.modele = modele;
		this.modele.ajoutEcouteur(this);
		nombreCoups = new JLabel("Nombre de coups joués " + modele.getNombreCoupsJoues());
		resetBoard = new JButton("Nouvelle partie");
		complexity = new JTextField();
		complexity.setColumns(5);
		nombreCoups.setHorizontalAlignment(SwingConstants.CENTER);
		nombreCoups.setFont(courrier);
		nombreCoups.setPreferredSize(new Dimension(300, 30));
		resetBoard.addActionListener(new ResetAction());
		resetBoard.setFocusable(false);
		help = new JButton("Afficher aide");
		help.addActionListener(new HelpAction());
		help.setFocusable(false);
		complexity.addKeyListener(new InputListener());
		this.add(nombreCoups);
		this.add(resetBoard);
		this.add(complexity);
		this.add(help);
	}

	/**
	 * Lors de la mise à jour de la Vue, les composants de cette dernière se mettent
	 * à jour : nombre de coups joués, partie finie.
	 */
	@Override
	public void modeleMisAJour(ModeleEcoutable source) {
		nombreCoups.setText("Nombre de coups joués " + modele.getNombreCoupsJoues());
		if (modele.isGameLauch() && modele.isFinished()) {
			JOptionPane.showMessageDialog(frame, "Bravo jeu terminé en " + modele.getNombreCoupsJoues() + " coups");
			new ResetAction().actionPerformed(null);
		}
	}

	/**
	 * Classe interne Controlleur, nouveau jeu de Taquin. Mélange le jeu.
	 */
	class ResetAction implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			try {
				int c = Integer.valueOf(complexity.getText());
				if (c <= 0)
					c = TaquinModel.DEFAULT_COMPLEXITY;
				modele.shuffleElements(c);
			} catch (Exception e) {
				modele.shuffleElements(TaquinModel.DEFAULT_COMPLEXITY);
			} finally {
				new HelpAction().cacher();
				modele.resetNombreCoupsJoues();
				frame.getVueTaquin().loadImages();
			}
		}
	}

	/**
	 * Classe interne Controlleur, affiche l'aide dans le jeu.
	 */
	class HelpAction implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			modele.requestHelp(!modele.getHelp());
			if (modele.getHelp())
				help.setText("Cacher l'aide");
			else
				help.setText("Afficher l'aide");
		}

		/**
		 * Cacher les aide du jeu
		 */
		public void cacher() {
			modele.requestHelp(false);
			help.setText("Afficher l'aide");
		}
	}

	/**
	 * Classe interne qui permet de spécifier la complexité du jeu pour le prochain
	 * lancement. Si des touches autre que les nombres sont tapées, le focus est
	 * donné au jeu.
	 */
	class InputListener implements KeyListener {

		@Override
		public void keyPressed(KeyEvent key) {
			if (key.getKeyCode() == KeyEvent.VK_ENTER) {
				new ResetAction().actionPerformed(null);
			} else {
				int k = key.getKeyCode();
				if (k != 16 && k != 20 && k < 96 || k > 105) {
					frame.getVueTaquin().requestFocusInWindow();
				}
			}
		}

		@Override
		public void keyReleased(KeyEvent arg0) {
		}

		@Override
		public void keyTyped(KeyEvent arg0) {
		}
	}
}
