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
namespace manage
{

	/**
	 * @brief Holt eine bestimmte Zeile aus einer Datei.
	 *
	 * @param filename Der Name der Datei.
	 * @param lineNumber Die Zeilennummer.
	 * @return std::string Die abgerufene Zeile.
	 */
	std::string getExactLine(const std::string &filename, int lineNumber);

	/**
	 * @brief Zeigt die Details einer Datei an.
	 *
	 * @param filename Der Name der Datei.
	 */
	void displayDetails(const std::string &filename);

	/**
	 * @brief Liest die Menge aus einer Datei.
	 *
	 * @param targetFile Der Name der Datei.
	 * @return std::string Die gelesene Menge.
	 */
	std::string readAmount(const std::string &targetFile);

	/**
	 * @brief Aktualisiert die Menge in einer Datei.
	 *
	 * @param targetFile Der Name der Datei.
	 * @param action Die auszuführende Aktion (0 für Subtraktion, 1 für Addition).
	 * @param amount Die zu aktualisierende Menge.
	 */
	void UpdateAmount(const std::string &targetFile, int action, int amount);

	/**
	 * @brief Liest den Zähler aus einer Datei.
	 *
	 * @return std::string Der gelesene Zähler.
	 */
	std::string readCounter();

	/**
	 * @brief Aktualisiert den Zähler in einer Datei.
	 *
	 * @param action Die auszuführende Aktion (0 für Subtraktion, 1 für Addition).
	 * @param amount Die zu aktualisierende Menge.
	 */
	void UpdateCounter(int action, int amount);

	/**
	 * @brief Konvertiert einen Suchbegriff in Kleinbuchstaben.
	 *
	 * @param searchTerm Der zu konvertierende Suchbegriff.
	 * @return std::string Der konvertierte Suchbegriff.
	 */
	std::string toLower(std::string searchTerm);

	/**
	 * @brief Holt den Suchbegriff vom Benutzer.
	 *
	 * @return std::string Der vom Benutzer eingegebene Suchbegriff.
	 */
	std::string getSearchTerm();

	/**
	 * @brief Durchsucht Dateien nach einem bestimmten Suchbegriff.
	 */
	void Search();

} // namespace manage
