Projet Listechainee
Ce projet est notre aventure collective, réalisée avec passion par Arthur Krings, Nicolas Guerfi-Braure et moi-même, Aymeric Thomine. Notre voyage dans le monde des listes chaînées en C a commencé avec une étincelle d'inspiration tirée du travail de notre professeur, rcoscali, sur GitHub.

Difficultés Rencontrées
On a dû affronter pas mal de tempêtes en cours de route. Le problème le plus tenace était cette réinitialisation automatique de notre liste curlist après chaque manipulation. C'était comme essayer de résoudre un puzzle sans cesse mouvant. On a passé des jours entiers à essayer de déjouer ce casse-tête.

Puis, il y avait l'énigme de insert_elem_into_list. Comment insérer efficacement sans pouvoir mettre des éléments en dessous de 0 ? Cette fonction nous a donné du fil à retordre, démontrant qu'on avait encore des stratégies à affiner.

Et parlons des opérations d'ajout et de suppression - append, prepend, remove. Techniquement, elles fonctionnaient. Mais à chaque fois, c'était comme si notre programme criait ses erreurs à qui voulait l'entendre, plusieurs fois d'affilée. Pas très élégant, même si, au fond, tout fonctionnait comme prévu.
Stratégie Adoptée
Face à ces défis, on a décidé de pivoter. On a choisi d'embrasser l'idée de sauvegarder et mettre à jour notre liste dans un fichier après chaque opération. Une sorte de journal de bord pour notre liste curlist, grâce à la fonction save_list.

Quant à insérer des éléments à des indices précis, on a opté pour une interaction directe avec l'utilisateur, qui doit maintenant spécifier l'index et la valeur. Cela a permis d'apporter une solution pratique à un problème technique persistant.

Utilisation du Menu Interactif
Le menu interactif, ah, c'était un autre champ de bataille. On a galéré à le mettre en place par nous-mêmes. Au final, intégrer le menu développé par rcoscali s'est avéré être notre planche de salut, enrichissant l'expérience utilisateur de manière significative.

Apprentissages
Ce projet nous a appris à regarder au-delà des problèmes immédiats, à être critiques envers notre code et à ne jamais abandonner, peu importe le temps nécessaire pour déboguer et perfectionner. Chaque obstacle surmonté a renforcé notre compréhension des listes chaînées et affiné notre art de la programmation en C.

Conclusion
Ce module a été une véritable aventure pour nous, Arthur, Nicolas, et moi. C'est une fierté de voir tout ce qu'on a accompli, même si on reconnaît que notre code pourrait être optimisé ou amélioré. Notre projet "Listechainee", avec toutes ses imperfections, est le témoignage de notre détermination et de notre croissance en tant que programmeurs.
