import cv2
import numpy as np

def linear_transformation(image):
    img = cv2.imread(image)

    linear_transformed = np.array(255 - img)

    cv2.imwrite('linear_transformed.jpg', linear_transformed)

def log_transformation(image):
    img = cv2.imread(image)

    c = 255/(np.log(1 + np.max(img)))
    log_transformed = c * np.log(1 + img)

    log_transformed = np.array(log_transformed, dtype = np.uint8)

    cv2.imwrite('log_transformed.jpg', log_transformed)

def power_transformation(image):
    img = cv2.imread(image)

    for gamma in [0.1, 0.5, 1.2, 2.2]:

        gamma_corrected = np.array(255*(img / 255) ** gamma, dtype = 'uint8')
    
        cv2.imwrite('gamma_transformed'+str(gamma)+'.jpg', gamma_corrected)

def piece_linear_transformation(image):
    def pixelVal(pix, r1, s1, r2, s2):
        if (0 <= pix and pix <= r1):
            return (s1 / r1)*pix
        elif (r1 < pix and pix <= r2):
            return ((s2 - s1)/(r2 - r1)) * (pix - r1) + s1
        else:
            return ((255 - s2)/(255 - r2)) * (pix - r2) + s2

    img = cv2.imread(image)

    r1 = 70
    s1 = 0
    r2 = 140
    s2 = 255
  
    pixelVal_vec = np.vectorize(pixelVal)

    contrast_stretched = pixelVal_vec(img, r1, s1, r2, s2)

    cv2.imwrite('contrast_stretch.jpg', contrast_stretched)

print("Enter the tranformation that you want to apply")
print("Select the image")
image = input()
print("1) Log Transformation" + '\n' + "2) Power Law Transformation" + '\n' + "3) Piecewise Linear Transformation" + '\n' + "4) Linear Transformation")
print("Enter your choice")
choice = int(input())

while True:
    if choice == 1:
        log_transformation(image)
        break
    elif choice == 2:
        power_transformation(image)
        break
    elif choice == 3:
        piece_linear_transformation(image)
        break
    elif choice == 4:
        linear_transformation(image)
        break
    else:
        print("Wrong input")