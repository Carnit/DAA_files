# main_file/__init__.py

from timer import Timer  # Assuming timer.py is in the same directory

# Re-export the Timer class for convenience
__all__ = ["Timer"]