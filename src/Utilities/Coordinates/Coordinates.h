//
// Created by Joe Ayoub on 22/12/24 at 16:40.
//

#ifndef INC_2024_PROJECT_JOE_AYOUB_UA_COORDINATES_H
#define INC_2024_PROJECT_JOE_AYOUB_UA_COORDINATES_H

/**
 * @brief Coordinates class
 */
class Coordinates {
private:
    /**
     * @brief x coordinate
     */
    float x{};
    /**
     * @brief y coordinate
     */
    float y{};
public:
    /**
     * @brief Default constructor for Coordinates class
     */
    Coordinates() = default;
    /**
     * @brief Constructor for Coordinates class
     * @param x : coordinate x
     * @param y : coordinate Y
     */
    Coordinates(float x, float y) : x(x), y(y) {}
    /**
     * @brief Getter for x
     * @return float : x
     */
    float getX() const {return x;}
    /**
     * @brief Setter for x
     * @param n_x : new x
     */
    void setX(float n_x) {Coordinates::x = n_x;}
    /**
     * @brief Getter for y
     * @return float : y
     */
    float getY() const {return y;}
    /**
     * @brief Setter for y
     * @param n_y : new y
     */
    void setY(float n_y) {Coordinates::y = n_y;}

    /**
     * @brief Overload of the == operator
     * @param lhs
     * @param rhs
     * @return
     */
    friend bool operator==(const Coordinates& lhs, const Coordinates& rhs) {return lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY();}
    /**
     * @brief Destructor for Coordinates class
     */
    virtual ~Coordinates()=default;
};
#endif //INC_2024_PROJECT_JOE_AYOUB_UA_COORDINATES_H
