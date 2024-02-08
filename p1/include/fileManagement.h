#pragma once

#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <vector>
#include "book.h"

/**
 * @brief Ein Namespace für die Verwaltung von Dateien.
 */
namespace manage {
    /**
     * @brief Liest eine bestimmte Zeile aus einer Datei.
     * 
     * Diese Funktion öffnet die Datei mit dem angegebenen Dateinamen, durchläuft sie Zeile für Zeile und liest
     * die gewünschte Zeile anhand der angegebenen Zeilennummer aus. Falls die Datei nicht geöffnet werden kann
     * oder die angegebene Zeile nicht gefunden wird, wird ein leerer String zurückgegeben.
     * 
     * @param filename Der Name der Datei, aus der die Zeile gelesen werden soll.
     * @param lineNumber Die Zeilennummer, die gelesen werden soll.
     * @return Die gelesene Zeile als String.
     */
    std::string getExactLine(const std::string& filename, int lineNumber);

    /**
     * @brief Zeigt die Details eines Buchs an.
     * 
     * Diese Funktion ruft die 'getExactLine'-Funktion auf, um den Titel, Autor, Verlag, ISBN und Preis
     * eines Buchs aus der angegebenen Datei zu erhalten und zeigt sie formatiert auf der Konsole an.
     * 
     * @param filename Der Name der Datei, die die Buchdetails enthält.
     */
    void displayDetails(const std::string& filename);

    /**
     * @brief Liest den Bestand eines Buchs aus einer Datei.
     * 
     * Diese Funktion öffnet die angegebene Datei und liest den aktuellen Bestand (Menge) des Buchs aus.
     * Wenn die Datei nicht geöffnet werden kann, wird eine Ausnahme ausgelöst.
     * 
     * @param targetFile Der Name der Datei, die den Bestand des Buchs enthält.
     * @return Die Menge des Buchs als String.
     */
    std::string readAmount(const std::string& targetFile);

    /**
     * @brief Schreibt einen neuen Betrag in eine Datei.
     * 
     * Diese Funktion öffnet die angegebene Datei und aktualisiert den Bestand (Menge) des Buchs.
     * Dabei wird der neue Betrag (Menge) als String in die Datei geschrieben.
     * Wenn die Datei nicht geöffnet werden kann, wird eine Ausnahme ausgelöst.
     * 
     * @param targetFile Der Name der Datei, die aktualisiert werden soll.
     * @param newString Der neue Betrag als String.
     */
    void writeAmountToFile(const std::string& targetFile, const std::string& newString);

    /**
     * @brief Aktualisiert den Bestand eines Buchs.
     * 
     * Diese Funktion liest den aktuellen Bestand aus der Datei, aktualisiert ihn basierend auf der angegebenen
     * Aktion (Hinzufügen oder Entfernen) und schreibt den neuen Bestand zurück in die Datei.
     * 
     * @param targetFile Der Name der Datei, die aktualisiert werden soll.
     * @param action Die auszuführende Aktion (0 für Entfernen, 1 für Hinzufügen).
     * @param amount Die Menge, die hinzugefügt oder entfernt werden soll.
     */
    void UpdateAmount(const std::string& targetFile, int action, int amount);

    /**
     * @brief Liest den aktuellen Stand des Zählers aus einer Datei.
     * 
     * Diese Funktion öffnet die Datei 'counter.txt' und liest den aktuellen Stand des Zählers aus.
     * Wenn die Datei nicht geöffnet werden kann, wird eine Ausnahme ausgelöst.
     * 
     * @return Der aktuelle Stand des Zählers als String.
     */
    std::string readCounter();

    /**
     * @brief Aktualisiert den Zählerwert.
     * 
     * Diese Funktion liest den aktuellen Stand des Zählers aus der Datei 'counter.txt',
     * aktualisiert ihn basierend auf der angegebenen Aktion (Erhöhen oder Verringern) und schreibt
     * den neuen Wert zurück in die Datei.
     * 
     * @param action Die auszuführende Aktion (0 für Verringern, 1 für Erhöhen).
     * @param amount Die Menge, um die der Zähler erhöht oder verringert werden soll.
     */
    void UpdateCounter(int action, int amount);

    /**
     * @brief Konvertiert einen Suchbegriff in Kleinbuchstaben.
     * 
     * Diese Funktion wandelt den übergebenen Suchbegriff in Kleinbuchstaben um und gibt ihn zurück.
     * 
     * @param searchTerm Der Suchbegriff, der konvertiert werden soll.
     * @return Der konvertierte Suchbegriff als String.
     */
    std::string toLower(std::string searchTerm);

    /**
     * @brief Liest einen Suchbegriff von der Benutzerkonsole.
     * 
     * Diese Funktion fordert den Benutzer auf, einen Suchbegriff einzugeben, und gibt diesen zurück.
     * 
     * @return Der eingegebene Suchbegriff als String.
     */
    std::string getSearchTerm();

    /**
     * @brief Durchsucht die Bücherdatenbank nach einem Suchbegriff.
     * 
     * Diese Funktion durchsucht die Bücherdatenbank nach einem angegebenen Suchbegriff
     * und gibt alle gefundenen Bücher mit ihren Details aus.
     */
    void Search();
}
