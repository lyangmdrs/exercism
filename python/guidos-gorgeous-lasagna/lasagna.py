"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language:
https://en.wikipedia.org/wiki/Guido_van_Rossum

This is a module docstring, used to describe the functionality
of a module and its functions and/or classes.
"""


EXPECTED_BAKE_TIME = 40
MINUTES_NEEDED_TO_PREPARE_A_LAYER = 2

def bake_time_remaining(elapsed_bake_time):
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """

    return EXPECTED_BAKE_TIME - elapsed_bake_time


def preparation_time_in_minutes(number_of_layers):
    """Calculates the preparation time of a lasagna in minutes
    
    :param number_of_layers: int - number of layers of the lasagna.
    :return: int - time in minutes needed to prepare all layers.

    Function that takes the number of layers of the lasagna as an argument and returns
    how many minutes will take to prepare all the layers based on `MINUTES_NEEDED_TO_COOK_A_LAYER`.
    """
    return MINUTES_NEEDED_TO_PREPARE_A_LAYER * number_of_layers


#TODO: define the 'elapsed_time_in_minutes()' function below.
# Remember to add a docstring (you can copy and then alter the one from bake_time_remaining.)
def elapsed_time_in_minutes(number_of_layers, elapsed_bake_time):
    """Calculates the time spent with preparation and baking of a lasagna in minutes
    
    :param number_of_layers: int - number of layers of the lasagna.
    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - time in minutes spent in preparation and baking.

    Function that takes the number of layers of the lasagna and the actual minutes the lasagna has been
    in the oven as arguments and returns how many minutes already have elapsed since the preparation started.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time
