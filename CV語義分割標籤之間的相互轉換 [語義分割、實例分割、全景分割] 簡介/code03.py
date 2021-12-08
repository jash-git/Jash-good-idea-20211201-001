def label_to_onehot(label, colormap):  
    """  
    Converts a segmentation label (H, W, C) to (H, W, K) where the last dim is a one  
    hot encoding vector, C is usually 1 or 3, and K is the number of class.  
    """  
    semantic_map = []  
    for colour in colormap:  
        equality = np.equal(label, colour)  
        class_map = np.all(equality, axis=-1)  
        semantic_map.append(class_map)  
    semantic_map = np.stack(semantic_map, axis=-1).astype(np.float32)  
    return semantic_map  

def onehot_to_label(semantic_map, colormap):  
    """  
    Converts a mask (H, W, K) to (H, W, C)  
    """  
    x = np.argmax(semantic_map, axis=-1)  
    colour_codes = np.array(colormap)  
    label = np.uint8(colour_codes[x.astype(np.uint8)])  
    return label  

colormap, classes = colormap_voc()  
semantic_map = mask_to_onehot(train_label, colormap)  
print(semantic_map.shape)  # [H, W, K] = [375, 500, 21] 包括背景共21个类别  

label = onehot_to_label(semantic_map, colormap)  
print(label.shape) # [H, W, K] = [375, 500, 3]  
