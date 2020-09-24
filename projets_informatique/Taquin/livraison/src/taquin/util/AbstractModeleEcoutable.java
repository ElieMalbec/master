package taquin.util;

import java.util.ArrayList;
import java.util.List;

/**
 * Classe abstraite hérité par les Modèles qui sont écoutés par leurs vues. Les
 * écouteurs sont prévenus lors d'un changement sur le modèle lors de l'appel de
 * la fonction notifyChangement.
 */
public abstract class AbstractModeleEcoutable implements ModeleEcoutable {

	/** Liste d'écouteur du modèle */
	private List<EcouteurModele> ecouteurs;

	public AbstractModeleEcoutable() {
		ecouteurs = new ArrayList<EcouteurModele>();
	}

	public AbstractModeleEcoutable(List<EcouteurModele> list) {
		ecouteurs = list;
	}

	/**
	 * Ajout d'un écouteur sur le modèle
	 * 
	 * @param e Ecouteur
	 */
	public void ajoutEcouteur(EcouteurModele e) {
		ecouteurs.add(e);
	}

	/**
	 * Retrait d'un écouteir sur le modèle
	 * 
	 * @param e Ecouteur
	 */
	public void retraitEcouteur(EcouteurModele e) {
		ecouteurs.remove(e);
	}

	/**
	 * Notifie tous les écouteurs qu'il y a eu un changement sur le modèle.
	 */
	protected void notifyChangement() {
		for (EcouteurModele e : ecouteurs) {
			e.modeleMisAJour(this);
		}
	}
}
