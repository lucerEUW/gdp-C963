#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>

/**
 * @brief Eine Klasse zur Verwaltung von Büchern.
 */
class Book {
public:
    /**
     * @brief Konstruktor für die Buchklasse.
     * 
     * @param titel Der Titel des Buches.
     * @param autor Der Autor des Buches.
     * @param verlag Der Verlag des Buches.
     * @param isbn Die ISBN des Buches.
     * @param preis Der Preis des Buches.
     * @param amount Die Anzahl der Exemplare des Buches.
     */
    Book(std::string titel, std::string autor, std::string verlag, long isbn, double preis, int amount);

    /**
     * @brief Fügt ein Buch zur Sammlung hinzu.
     */
    void Add();

    /**
     * @brief Kauft ein Buch.
     * 
     * @param bookToBuy Das zu kaufende Buch.
     */
    static void Buy(const std::string& bookToBuy);

    /**
     * @brief Bestellt weitere Exemplare eines Buches.
     * 
     * @param bookToRestock Das Buch, das aufgestockt werden soll.
     */
    static void Restock(const std::string& bookToRestock);

private:
    std::string titel;    
    std::string autor;   
    std::string verlag; 
    long isbn;         
    double preis;     
    int amount;      
    std::string bookFile;
};
