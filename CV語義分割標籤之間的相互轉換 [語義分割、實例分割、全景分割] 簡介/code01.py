import os  
from tensorbay import GAS  
from tensorbay.dataset import Data, Dataset  
from tensorbay.label import InstanceMask, SemanticMask  
from PIL import Image  
import numpy as np  
import torchvision  
import matplotlib.pyplot as plt  

ACCESS_KEY = "<YOUR_ACCESSKEY>"  
gas = GAS(ACCESS_KEY)  


def read_voc_images(is_train=True, index=0):  
    """  
    read voc image using tensorbay  
    """  
    dataset = Dataset("VOC2012Segmentation", gas)  
    if is_train:  
        segment = dataset["train"]  
    else:  
        segment = dataset["test"]  

    data = segment[index]  
    feature = Image.open(data.open()).convert("RGB")  
    label = Image.open(data.label.semantic_mask.open()).convert("RGB")  
    visualize(feature, label)  
      
    return feature, label  # PIL Image  

  

def visualize(feature, label):  
    """  
    visualize feature and label  
    """  
    fig = plt.figure()  
    ax = fig.add_subplot(121)  # 第一个子图  
    ax.imshow(feature)  
    ax2 = fig.add_subplot(122)  # 第二个子图  
    ax2.imshow(label)  
    plt.show()  

train_feature, train_label = read_voc_images(is_train=True, index=10)  
train_label = np.array(train_label) # (375, 500, 3)  