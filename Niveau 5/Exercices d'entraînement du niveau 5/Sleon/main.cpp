#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int D, M;
  std::cin >> D >> M;
  std::unordered_map<std::string, std::string> dictionary;
  std::vector<std::string> article;
  // Lire et prétraiter chaque mot du dictionnaire
  for (int i = 0; i < D; ++i)
  {
    std::string original_word;
    std::cin >> original_word;
    // Créer une clé triée pour le dictionnaire
    std::string sorted_key = original_word;
    if (sorted_key.size() > 2)
    {
      sort(sorted_key.begin() + 1, sorted_key.end() - 1);
    }
    // Insérer dans le dictionnaire
    dictionary [sorted_key] = original_word;
  }
  /* for (auto i : dictionary)
    std::cout << i.first << " " << i.second << '\n';
  std::cout << '\n'; */
  // Lire et traiter chaque mot de l'article mélangé
  for (int i = 0; i < M; ++i)
  {
    std::string mixed_word;
    std::cin >> mixed_word;
    // Créer une clé triée pour l'article
    std::string sorted_key = mixed_word;
    if (sorted_key.size() > 2)
      sort(sorted_key.begin() + 1, sorted_key.end() - 1);
    // Récupérer le mot original à partir du dictionnaire
    auto it = dictionary.find(sorted_key);
    if (it != dictionary.end())
    {
      article.push_back(it->second);
    }
    else
    {
      // Gérer le cas où le mot n'est pas trouvé dans le dictionnaire (optionnel)
      // Peut-être afficher un message d'erreur ou prendre une autre action
    }
  }
  // Afficher l'article reconstruit
  int count = 0;
  for (int i = 0; i < M; ++i)
  {
    if (count == 10)
    {
      std::cout << '\n';
      count = 0;
    }
    //if (i > 0)
    //{
    //  cout << " ";
    //}
    std::cout << article [i] << " ";
    count++;
  }
  std::cout << '\n';
  return 0;
}
