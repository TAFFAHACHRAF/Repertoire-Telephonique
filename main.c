#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define max 100
int v=0,i;
char r;
char n[max];
char p[max];
char tel[max];
FILE* repertoire = NULL;
FILE* rept = NULL;
typedef struct
{
	char nom[max];
	char prenom[max];
	char numtel[max];
}Personne;
typedef struct
{
	char *a;
}label;
Personne pers;
void AjouterUnePersonne();
void AffcherLaListeDesPersonnes();
void SupprimerUnePersonne();
void TrierParNom();
void ChercherUnNumeroDeTel();
void Menu()
{
	system("cls");
	printf("                                      sNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm+\n");
	Sleep(100);
	printf("                                      MM..........................................:MM\n");
	Sleep(100);
	printf("                                      MM  +ho.                               -od/ -MM\n");
	Sleep(100);
	printf("                                      MM  .omNh/`                         `/dMmo` -MM\n");
	Sleep(100);
	printf("                                 `    MM    `:hNNs-                     :yNNy:`   -MM\n");
	Sleep(100);
	printf("                             `/ymNNy. MM       .+dNd+`               .+dNd+`      -MM\n");
	Sleep(100);
	printf("                          `/hNmy/.oMN/MM         `-yNNy:          `/hNms-`        -MM\n");
	Sleep(100);
	printf("                         .dMy:`    :mMMM            `+hNmo.     -omNh/`           -MM\n");
	Sleep(100);
	printf("                         hMs        .hMM.             `-smNh/-/dNdo.              -MM\n");
	Sleep(100);
	printf("                         MM.         `oMm:          -o:  `/hdmdy:`  /o-           -MM\n");
	Sleep(100);
	printf("                         MM`           /NN+       .yNd:     `.`     /mNs.         -MM\n");
	Sleep(100);
	printf("                         mM/           `sMd     .sNm+`               `omNo.       -MM\n");
	Sleep(100);
	printf("                         +Md         -smNy-   `omNo.                   .sNm+`     -MM\n");
	Sleep(100);
	printf("                         `dMo      `hNdo.   `+mNy.                       -yNd/`   -MM\n");
	Sleep(100);
	printf("                          .mM+     .MM:    :dMy-                           :hNh:  -MM\n");
	Sleep(100);
	printf("                           -mMo     oMm/  +Nh:                              `:dm/ -MM\n");
	Sleep(100);
	printf("                            .dMy`    /NNo``-`                                 `-` -MM\n");
	Sleep(100);
	printf("                             `sNm:    .hMdhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhdNh\n");
	Sleep(100);
	printf("                               /mNs`    /mMNs\n");
	Sleep(100);
	printf("                                `sNm/`   `+mNy-           ...`\n");
	Sleep(100);
	printf("                                  -hMh:`   `+mNy:`      -yNmmdo-`\n");
	Sleep(100);
	printf("                                    /dMh:    `/hNdo-` `+NN+`-omNdo.`\n");
	Sleep(100);
	printf("                                      /dMh:`    -odNdydMh.     -omNdo.`\n");
	Sleep(100);
	printf("                                        /dMd/`     ./oo:          -smNh:\n");
	Sleep(100);
	printf("                                          :yNms-                     +MM\n");
	Sleep(100);
	printf("                                            .omMd+.                 -mMo\n");
	Sleep(100);
	printf("                                               -smMds:`            :NM/\n");
	Sleep(100);
	printf("                                                  -+hNNdy+:-.``.-/yMm:\n");
	Sleep(100);
	printf("                                                      -/shdmNMMNNdy/\n\n\n\n");
	Sleep(100);
	choix:
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                            Repertoire Telephonique                           |\n");
	Sleep(100);
	printf("                |                                                                              |\n");
	Sleep(100);
	printf("                |                                 realise par                                  |\n");
	Sleep(100);
	printf("                |                                      :                                       |\n");
	Sleep(100);
	printf("                |                               Achraf TAFFAH                                  |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("                                    ++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                                    |                                      |\n");
	Sleep(100);
	printf("                                    | 1 ==> Ajouter une personne           |\n");
	Sleep(100);
	printf("                                    | 2 ==> Affcher la liste des personnes |\n");
	Sleep(100);
	printf("                                    | 3 ==> Supprimer une personne         |\n");
	Sleep(100);
	printf("                                    | 4 ==> Trier par nom                  |\n");
	Sleep(100);
	printf("                                    | 5 ==> Chercher un numero de tel      |\n");
	Sleep(100);
	printf("                                    | 6 ==> Quitter                        |\n");
	Sleep(100);
	printf("                                    ++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("                                         Veuillez choisir une action  :" );
	scanf("%d",&i );
	switch(i){
		case 1:
		 	AjouterUnePersonne();
			system("cls");
		goto choix;
		case 2:
			AffcherLaListeDesPersonnes();
			system("cls");
			goto choix;
		case 3:
			SupprimerUnePersonne();
			system("cls");
			goto choix;
		case 4:
			TrierParNom();
			system("cls");
			goto choix;
		case 5:
			ChercherUnNumeroDeTel();
			system("cls");
			goto choix;
		case 6:
		system("exit");
	}
}
void CreationDeficher()
{
	repertoire = fopen("repertoire.txt","a");
	while(repertoire == NULL)
	{
		repertoire = fopen("repertoire.txt","a");
	}
}
void AjouterUnePersonne()
{

	gets(pers.nom);
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                             Ajouter une personne                             |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	repertoire = fopen("repertoire.txt","a");
	label t[3];
 	t[0].a="le nom";
 	t[1].a="le prenom";
 	t[2].a="le numero de telephone";
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
	printf("\n");
	Sleep(100);
 	printf("                                 entrez %s: ",t[0].a);
	gets(pers.nom);
	printf("                              entrez %s: ",t[1].a);
	gets(pers.prenom);
	printf("                          entrez %s: ",t[2].a);
	gets(pers.numtel);
	fprintf(repertoire, "%s\n",pers.nom);
	fprintf(repertoire, "%s\n",pers.prenom);
	fprintf(repertoire, "%s\n",pers.numtel);
	fclose(repertoire);
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                     La personne a ete ajouter avec suces                     |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	system("color 2");
	printf("                                               ./oydmNMMMMNmdyo/`\n");
	Sleep(100);
	printf("                                            -smMMMMMMMMMMMMMMMMMMms:\n");
	Sleep(100);
	printf("                                          +mMMMMMMMMMMMMMMMMMMMMMMMMm\n");
	Sleep(100);
	printf("                                        /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/\n");
	Sleep(100);
	printf("                                      `hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
	Sleep(100);
	printf("                                     .mMMMMMMMMMMMMMMMMMMMMMMMMmdmMMMMMMMm.\n");
	Sleep(100);
	printf("                                     dMMMMMMMMMMMMMMMMMMMMMMMh-   -NMMMMMMd\n");
	Sleep(100);
	printf("                                    +MMMMMMMMMMMMMMMMMMMMMMh-      dMMMMMMM+\n");
	Sleep(100);
	printf("                                    mMMMMMMMMNhshNMMMMMMMh-      :dMMMMMMMMN\n");
	Sleep(100);
	printf("                                    MMMMMMMMm`   `oNMMMh-      :mMMMMMMMMMMM\n");
	Sleep(100);
	printf("                                    MMMMMMMMm.     `oh-      -hMMMMMMMMMMMMM\n");
	Sleep(100);
	printf("                                    NMMMMMMMMNs`           -hMMMMMMMMMMMMMMm\n");
	Sleep(100);
	printf("                                    +MMMMMMMMMMNs`       :hMMMMMMMMMMMMMMMM+\n");
	Sleep(100);
	printf("                                     dMMMMMMMMMMMNs`   /mMMMMMMMMMMMMMMMMMd\n");
	Sleep(100);
	printf("                                     .mMMMMMMMMMMMMMddNMMMMMMMMMMMMMMMMMMm.\n");
	Sleep(100);
	printf("                                      `hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
	Sleep(100);
	printf("                                        /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/\n");
	Sleep(100);
	printf("                                          +mMMMMMMMMMMMMMMMMMMMMMMMMm+\n");
	Sleep(100);
	printf("                                            -smMMMMMMMMMMMMMMMMMMms-\n");
	Sleep(100);
	printf("                                               `:oydmNMMMMNmdyo:`\n");
	system("color 7");
	printf("                                  Cliquer sur 'B' pour retourner au Menu :");
	scanf("%c",&r);
	while(r!='B'&&r!='b')
	{
		scanf("%c",&r);
	}
}
void AffcherLaListeDesPersonnes()
{
	label t[3];
 	t[0].a="le nom";
 	t[1].a="le prenom";
 	t[2].a="le numero de telephone";
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                            La liste des personnes                            |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	repertoire = fopen("repertoire.txt","a");
	fclose(repertoire);
	repertoire = fopen("repertoire.txt","r");
	while (fgets(pers.nom,max,repertoire)!= NULL) {
		fgets(pers.prenom,max,repertoire);
		fgets(pers.numtel,max,repertoire);
		printf("\n%s : %s",t[0].a,pers.nom);
		Sleep(100);
	  printf("%s : %s",t[1].a,pers.prenom);
		Sleep(100);
	  printf("%s : %s",t[2].a,pers.numtel);
		Sleep(100);
		printf("________________________________________________________________________________\n");
		Sleep(100);
	}
	printf("                  Cliquer sur 'B' pour retourner au Menu :");
	scanf("%c",&r);
	while(r!='B'&&r!='b')
	{
		scanf("%c",&r);
	}
}
void SupprimerUnePersonne()
{
	repertoire = fopen("repertoire.txt","r");
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                            Supprimer une personne                            |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n\n");
	Sleep(100);
	printf("                             Entrez le nom de la personne que vous voulez supprimer\n                                        :\n                                        ");
	scanf("%s",n);
	printf("                           Entrez le prenom de la personne que vous voulez supprimer\n                                        :\n                                        ");
	scanf("%s",p);
	strcat(n,"\n");
	strcat(p,"\n");
	while (fgets(pers.nom,max,repertoire)!= NULL)
	{
		fgets(pers.prenom,max,repertoire);
		fgets(pers.numtel,max,repertoire);
		if (strcmp(n,pers.nom)!=0 && strcmp(p,pers.prenom)!=0)
		{
			rept = fopen("rept.txt","a");
			fprintf(rept,"%s",pers.nom);
			fprintf(rept,"%s",pers.prenom);
			fprintf(rept,"%s",pers.numtel);
			fclose(rept);
		}
		else if(strcmp(n,pers.nom)==0 && strcmp(p,pers.prenom)==0)
		{
			v=2;
		}
	}
	if (v!=0)
	{
		system("cls");
		printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		Sleep(100);
		printf("                |                    La personne a ete supprimer avec suces                    |\n");
		Sleep(100);
		printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		system("color 2");
    printf("                                               ./oydmNMMMMNmdyo/`\n");
		Sleep(100);
    printf("                                            -smMMMMMMMMMMMMMMMMMMms:\n");
		Sleep(100);
    printf("                                          +mMMMMMMMMMMMMMMMMMMMMMMMMm\n");
		Sleep(100);
    printf("                                        /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/\n");
		Sleep(100);
    printf("                                      `hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
		Sleep(100);
    printf("                                     .mMMMMMMMMMMMMMMMMMMMMMMMMmdmMMMMMMMm.\n");
		Sleep(100);
    printf("                                     dMMMMMMMMMMMMMMMMMMMMMMMh-   -NMMMMMMd\n");
		Sleep(100);
    printf("                                    +MMMMMMMMMMMMMMMMMMMMMMh-      dMMMMMMM+\n");
		Sleep(100);
    printf("                                    mMMMMMMMMNhshNMMMMMMMh-      :dMMMMMMMMN\n");
		Sleep(100);
    printf("                                    MMMMMMMMm`   `oNMMMh-      :mMMMMMMMMMMM\n");
		Sleep(100);
    printf("                                    MMMMMMMMm.     `oh-      -hMMMMMMMMMMMMM\n");
		Sleep(100);
    printf("                                    NMMMMMMMMNs`           -hMMMMMMMMMMMMMMm\n");
		Sleep(100);
    printf("                                    +MMMMMMMMMMNs`       :hMMMMMMMMMMMMMMMM+\n");
		Sleep(100);
    printf("                                     dMMMMMMMMMMMNs`   /mMMMMMMMMMMMMMMMMMd\n");
		Sleep(100);
    printf("                                     .mMMMMMMMMMMMMMddNMMMMMMMMMMMMMMMMMMm.\n");
		Sleep(100);
    printf("                                      `hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
		Sleep(100);
    printf("                                        /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMN/\n");
		Sleep(100);
    printf("                                          +mMMMMMMMMMMMMMMMMMMMMMMMMm+\n");
		Sleep(100);
    printf("                                            -smMMMMMMMMMMMMMMMMMMms-\n");
		Sleep(100);
    printf("                                               `:oydmNMMMMNmdyo:`\n");
		system("color 7");
		printf("                                  Cliquer sur 'B' pour retourner au Menu :");
		scanf("%c",&r);
		while(r!='B'&&r!='b')
		{
			scanf("%c",&r);
		}
	}
	else
	{
		system("cls");
		printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		Sleep(100);
		printf("                |           je n'ai pas trouve la personne que vous voulez supprimer           |\n");
		Sleep(100);
		printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
		Sleep(100);
		system("color 4");
    printf("                                                  .:+osyyyyso/-`\n");
		Sleep(100);
    printf("                                              -ohNMMMMMMMMMMMMMMmy/`\n");
		Sleep(100);
    printf("                                           `omMMMMMMMMMMMMMMMMMMMMMMh:\n");
		Sleep(100);
    printf("                                         `sNMMMMMMMMMMMMMMMMMMMMMMMMMMm/\n");
		Sleep(100);
    printf("                                        :NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
		Sleep(100);
    printf("                                       +MMMMMMMMh+:/yMMMMMMMmo//omMMMMMMMm.\n");
		Sleep(100);
    printf("                                      /MMMMMMMMs     `sNMMm+     `NMMMMMMMm`\n");
		Sleep(100);
    printf("                                     `NMMMMMMMMy       `o+       .NMMMMMMMMy\n");
		Sleep(100);
    printf("                                     +MMMMMMMMMMm+             .sMMMMMMMMMMM`\n");
		Sleep(100);
    printf("                                     sMMMMMMMMMMMMNo         -sMMMMMMMMMMMMM-\n");
		Sleep(100);
    printf("                                     sMMMMMMMMMMMMd:         `oNMMMMMMMMMMMM-\n");
		Sleep(100);
    printf("                                     +MMMMMMMMMMd:             `oNMMMMMMMMMN`\n");
		Sleep(100);
    printf("                                     `NMMMMMMMMy       .yo       `NMMMMMMMMs\n");
		Sleep(100);
    printf("                                      :MMMMMMMMy     .yMMMNo     `NMMMMMMMm`\n");
		Sleep(100);
    printf("                                       /MMMMMMMMmo+ohMMMMMMMNs++yNMMMMMMMm`\n");
		Sleep(100);
    printf("                                        -mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy`\n");
		Sleep(100);
    printf("                                          +NMMMMMMMMMMMMMMMMMMMMMMMMMMd-\n");
		Sleep(100);
    printf("                                           `/dMMMMMMMMMMMMMMMMMMMMMNy- \n");
		Sleep(100);
    printf("                                              `/ymMMMMMMMMMMMMMNds:\n");
		Sleep(100);
    printf("                                                  `-:+oosso+/:.\n");
		system("color 7");
		printf("                                  Cliquer sur 'B' pour retourner au Menu :");
		scanf("%c",&r);
		while(r!='B'&&r!='b')
		{
			scanf("%c",&r);
		}
	}
	fclose(rept);
	fclose(repertoire);
	system("del repertoire.txt");
	system("rename rept.txt repertoire.txt");
}
void ChercherUnNumeroDeTel()
{
	repertoire = fopen("repertoire.txt","r");
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                        Chercher un numero de telephone                       |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n\n\n\n\n\n");
	Sleep(100);
	printf("                             Entrez le nom de la personne que vous voulez son numero\n                                                                        :\n                                                                        ");
	scanf("%s",n);
	printf("           Entrez le prenom de la personne que vous voulez son numero\n                                                                        :\n                                                                        ");
	scanf("%s",p);
	strcat(n,"\n");
	strcat(p,"\n");
	while (fgets(pers.nom,max,repertoire)!= NULL)
	{
		fgets(pers.prenom,max,repertoire);
		fgets(pers.numtel,max,repertoire);
		if (strcmp(n,pers.nom)==0 && strcmp(p,pers.prenom)==0)
		{
			system("cls");
			printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
			Sleep(100);
			printf("                |                         Numero de telephone trouver                          |\n");
			Sleep(100);
			printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n\n\n\n\n\n");
			Sleep(100);
			printf("                             le numero de telephone que vous Cherchez est : %s",pers.numtel);
			goto m;
		}
	}
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |               je n'ai pas trouve la personne que vous cherchez               |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	system("color 4");
	printf("                                                  .:+osyyyyso/-`\n");
	Sleep(100);
	printf("                                              -ohNMMMMMMMMMMMMMMmy/`\n");
	Sleep(100);
	printf("                                           `omMMMMMMMMMMMMMMMMMMMMMMh:\n");
	Sleep(100);
	printf("                                         `sNMMMMMMMMMMMMMMMMMMMMMMMMMMm/\n");
	Sleep(100);
	printf("                                        :NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh`\n");
	Sleep(100);
	printf("                                       +MMMMMMMMh+:/yMMMMMMMmo//omMMMMMMMm.\n");
	Sleep(100);
	printf("                                      /MMMMMMMMs     `sNMMm+     `NMMMMMMMm`\n");
	Sleep(100);
	printf("                                     `NMMMMMMMMy       `o+       .NMMMMMMMMy\n");
	Sleep(100);
	printf("                                     +MMMMMMMMMMm+             .sMMMMMMMMMMM`\n");
	Sleep(100);
	printf("                                     sMMMMMMMMMMMMNo         -sMMMMMMMMMMMMM-\n");
	Sleep(100);
	printf("                                     sMMMMMMMMMMMMd:         `oNMMMMMMMMMMMM-\n");
	Sleep(100);
	printf("                                     +MMMMMMMMMMd:             `oNMMMMMMMMMN`\n");
	Sleep(100);
	printf("                                     `NMMMMMMMMy       .yo       `NMMMMMMMMs\n");
	Sleep(100);
	printf("                                      :MMMMMMMMy     .yMMMNo     `NMMMMMMMm`\n");
	Sleep(100);
	printf("                                       /MMMMMMMMmo+ohMMMMMMMNs++yNMMMMMMMm`\n");
	Sleep(100);
	printf("                                        -mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy`\n");
	Sleep(100);
	printf("                                          +NMMMMMMMMMMMMMMMMMMMMMMMMMMd-\n");
	Sleep(100);
	printf("                                           `/dMMMMMMMMMMMMMMMMMMMMMNy- \n");
	Sleep(100);
	printf("                                              `/ymMMMMMMMMMMMMMNds:\n");
	Sleep(100);
	printf("                                                  `-:+oosso+/:.\n");
	system("color 7");
	m:
	printf("                                    Cliquer sur 'B' pour retourner au Menu :");
	scanf("%c",&r);
	while(r!='B'&&r!='b')
	{
		scanf("%c",&r);
	}
}
void TrierParNom()
{
	system("cls");
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	Sleep(100);
	printf("                |                         La liste des personnes trier                         |\n");
	Sleep(100);
	printf("                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
	Sleep(100);
	system("color B");
	int j=0,k=1;
	v=0;
	repertoire = fopen("repertoire.txt","r");
	while (fgets(pers.nom,max,repertoire)!= NULL)
	{
		fgets(pers.prenom,max,repertoire);
		fgets(pers.numtel,max,repertoire);
		j++;
	}
	fclose(repertoire);
	repertoire = fopen("repertoire.txt","r");
	Personne Perso[j];
	while (fgets(Perso[v].nom,max,repertoire)!= NULL)
	{
		fgets(Perso[v].prenom,max,repertoire);
		fgets(Perso[v].numtel,max,repertoire);
		v++;
	}
	while (k!=0)
	{
		k=0;
		for (v=0; v < j-1; v++)
		{
			if(strcmp(Perso[v].nom,Perso[v+1].nom)>=0)
			{
				strcpy(n,Perso[v].nom);
				strcpy(Perso[v].nom,Perso[v+1].nom);
				strcpy(Perso[v+1].nom,n);
				strcpy(p,Perso[v].prenom);
				strcpy(Perso[v].prenom,Perso[v+1].prenom);
				strcpy(Perso[v+1].prenom,p);
				strcpy(p,Perso[v].numtel);
				strcpy(Perso[v].numtel,Perso[v+1].numtel);
				strcpy(Perso[v+1].numtel,p);
				k=1;
			}
		}
	}
	for (v=0; v < j; v++)
	{
		printf("Le nom : %s",Perso[v].nom);
		Sleep(100);
		printf("Le prenom : %s",Perso[v].prenom);
		Sleep(100);
		printf("le numero de telephone : %s",Perso[v].numtel);
		Sleep(100);
		printf("_____________________________________________________________________________________________________________\n");
		Sleep(100);
	}
	fclose(repertoire);
	system("color 7");
	printf("                                    Cliquer sur 'B' pour retourner au Menu :");
	scanf("%c",&r);
	while(r!='B'&&r!='b')
	{
		scanf("%c",&r);
	}
}
int main()
{
	CreationDeficher();
	Menu();
 	return 0;
}
