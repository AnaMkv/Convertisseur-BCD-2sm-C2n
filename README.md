# 🔢 Convertisseur de Représentations Numériques

Un programme en ligne de commande pour convertir un nombre entier dans différents formats de représentation numérique, notamment BCD (Binary-Coded Decimal), complément à 2n (c2n), et représentation en signe et module (2sm).

---

## 📝 Fonctionnalités

- **💡 BCD (Binary-Coded Decimal)** : Convertit un nombre entier positif en représentation BCD compacté.
- **🔀 Signe-Module** : Affiche la représentation d'un entier en signe et module.
- **🧮 Complément à 2n** : Calcule le complément à 2n d'un nombre entier pour les représentations binaires.
- **🔍 Validation d'Entrées** : Gère les entrées invalides, comme les nombres négatifs pour certaines conversions.

---

## ⚙️ Prérequis

- **Compilateur C** : Un compilateur C comme GCC ou MSVC est nécessaire.

---

## 🚀 Installation

1. **Cloner le dépôt :**
   ```bash
   git clone https://github.com/AnaMkv/Convertisseur-BCD-2sm-C2n.git
   cd Convertisseur-BCD-2sm-C2n
   ```
2. **Compilez le code**
   ```bash
   gcc main.c -o convertisseur_numerique -lm
   ```
3. **Exécutez le fichier compilé**
   ```bash
   ./convertisseur_numerique
   ```

---

# 💻 Utilisation

1. **Exécution** : Lancez le programme et entrez un nombre suivi du format de conversion souhaité.
2. **Saisie des Détails** :
   - Par exemple : 1234 bcd pour obtenir la représentation BCD de 1234.
   - Utilisez les commandes :
     - bcd pour Binary-Coded Decimal
     - 2sm pour la représentation en signe et module
     - c2n pour le complément à 2n
3. **Résultats** : Le programme affiche la représentation choisie. Vous pouvez entrer exit pour quitter le programme.

---

# ⚠️ Limitations

- **Nombres Négatifs en BCD** : Le format BCD n’accepte que les nombres positifs ; les nombres négatifs produisent une erreur.
- **Entrées Non Numériques** : Seules les entrées numériques sont acceptées, sinon un comportement indéfini peut survenir.
- **Pas d’Interface Graphique** : Interface en ligne de commande uniquement.

---

# 🤝 Contributions

Les contributions sont bienvenues ! N’hésitez pas à :
- Ouvrir des issues pour signaler des bugs ou proposer des améliorations.
- Soumettre des pull requests pour ajouter des fonctionnalités.

---

# 📄 Licence

Le code est sous licence GPL-v3. Vous pouvez le télécharger, le modifier et le partager librement, tant que vous le faites gratuitement. :)
