#include "FileSystem.hpp"
#include "Directory.hpp"
#include "File.hpp"
#include <iostream>

using namespace std;

int main()
{
  FileSystem fs("ramfs");

  // QUELQUES TESTS
  if(fs.get_name() != "ramfs")
    cerr << "Problème: le nom de fs n'est pas \"ramfs\"" << endl;
  if(fs.get_root()->get_name() != "root")
    cerr << "Problème: le nom du dossier racine n'est pas \"root\"" << endl;
  if(fs.get_root()->find_node("truc") != nullptr)
    cerr << "Problème: le dossier racine contient un nœud" << endl;
  if(fs.get_root()->remove_node("truc") != false)
    cerr << "Problème: l'opération de suppression de nœud a réussi alors que le dossier est vide" << endl;
  if(fs.get_root()->add_file("truc") == nullptr)
  {
    cerr << "Problème: add_file a renvoyé un pointeur nul lors de l'ajout d'un fichier à la racine" << endl;
  }
  else if(fs.get_root()->remove_node("truc") != true)
  {
    cerr << "Problème: remove_node a échoué alors qu'il aurait dû réussir" << endl;
  }
  // FIN DES TESTS

  File *temp_file = nullptr;
  Directory *temp_dir = nullptr;

  // CRÉATION D'UN FICHIER AVEC ATTRIBUTION D'UN CONTENU
  temp_file = fs.get_root()->add_file("rootfile");
  temp_file->set_content("This is a file at root.");

  // UN TEST DE find_node
  if((temp_file = fs.get_root()->find_node("rootfile")->to_file()) == nullptr || temp_file->get_name() != "rootfile")
  {
    cerr << "Problème: find_node ne trouve pas le bon fichier" << endl;
  }
  // FIN DU TEST

  // UN TEST DU CALCUL DE TAILLE
  if(temp_file->size() != (int)string("This is a file at root.").size())
    cerr << "Problème: la taille du fichier n'est pas correctement calculée" << endl;
  // FIN DU TEST

  // CRÉATION DE FICHIERS ET DE DOSSIERS
  temp_dir = fs.get_root()->add_directory("dirA");

  temp_file = temp_dir->add_file("fileAA");
  temp_file->set_content("This is file AA.");

  temp_file = temp_dir->add_file("fileAB");
  temp_file->set_content("This is file AB.");

  temp_dir = fs.get_root()->add_directory("dirB");

  temp_file = temp_dir->add_file("fileBA");
  temp_file->set_content("This is file BA.");

  temp_file = temp_dir->add_file("fileBB");
  temp_file->set_content("This is file BB.");

  // TESTS DES MÉTHODES VIRTUELLES DE FILE ET DIRECTORY
  Node *temp_node = temp_file;
  if(temp_node->is_directory())
    cerr << "Problème: is_directory() ne renvoie pas la bonne valeur sur un nœud qui est un fichier" << endl;
  if(temp_node->to_file() == nullptr)
    cerr << "Problème: to_file() renvoie un pointeur nul sur un nœud fichier" << endl;
  if(temp_node->to_directory() != nullptr)
    cerr << "Problème: to_directory() renvoie un pointeur non nul sur un nœud fichier" << endl;
  if(temp_node->size() != (int) 16)
    cerr << "Problème: mauvais calcul de la taille d'un fichier" << endl;
  temp_node = temp_dir;
  if(!temp_node->is_directory())
    cerr << "Problème: is_directory() ne renvoie pas la bonne valeur sur un nœud qui est un dossier" << endl;
  if(temp_node->to_file() != nullptr)
    cerr << "Problème: to_file() renvoie un pointeur non nul sur un nœud dossier" << endl;
  if(temp_node->to_directory() == nullptr)
    cerr << "Problème: to_directory() renvoie un pointeur nul sur un nœud fichier" << endl;
  if(temp_node->size() != (int) 32)
    cerr << "Problème: mauvais calcul de la taille d'un dossier" << endl;
  // FIN DES TESTS

  // AFFICHAGE
  cout << "Affichage du système de fichiers:" << endl;
  cout << fs << endl;
  // devrait afficher:
  // filesystem "ramfs"
  // + directory: "root", uid: 0, size: 87
  //  + file: "rootfile", uid: 2, size: 23, content: "This is a file at root."
  //  + directory: "dirA", uid: 3, size: 32
  //   + file: "fileAA", uid: 4, size: 16, content: "This is file AA."
  //   + file: "fileAB", uid: 5, size: 16, content: "This is file AB."
  //  + directory: "dirB", uid: 6, size: 32
  //   + file: "fileBA", uid: 7, size: 16, content: "This is file BA."
  //   + file: "fileBB", uid: 8, size: 16, content: "This is file BB."
  // (les uid peuvent être différents des vôtres)

  // TESTS DE SUPPRESSION D'UN FICHIER ET D'UN DOSSIER
  if(!fs.get_root()->remove_node("rootfile"))
  {
    cerr << "Problème: échec de la suppression de \"rootfile\"" << endl;
  }
  if(!fs.get_root()->remove_node("dirA"))
  {
    cerr << "Problème: échec de la suppression de \"dirA\"" << endl;
  }
  // FIN DES TESTS

  // AFFICHAGE APRÈS SUPPRESSION D'UN FICHIER ET D'UN DOSSIER
  cout << "Affichage après suppression de \"rootfile\" et \"dirA\":" << endl;
  cout << fs;
  // devrait afficher:
  // filesystem "ramfs"
  // + directory: "root", uid: 0, size: 32
  //  + directory: "dirB", uid: 6, size: 32
  //   + file: "fileBA", uid: 7, size: 16, content: "This is file BA."
  //   + file: "fileBB", uid: 8, size: 16, content: "This is file BB."
  // (les uid peuvent être différents des vôtres)
  return 0;
}
