import cv2
import numpy as np
from matplotlib import pyplot as plt

#membuat koordinat
img = np.zeros((512,512,3), np.uint8)

#membuat garis
img = cv2.line(img,(0,0),(511,511),(255,0,0),3)

#Menampilkan gambar
plt.imshow(img)
plt.show()
