def onehot2mask(semantic_map):  
    """  
    Converts a mask (K, H, W) to (H,W)  
    """  
    _mask = np.argmax(semantic_map, axis=0).astype(np.uint8)  
    return _mask  


def mask2onehot(mask, num_classes):  
    """  
    Converts a segmentation mask (H,W) to (K,H,W) where the last dim is a one  
    hot encoding vector  

    """  
    semantic_map = [mask == i for i in range(num_classes)]  
    return np.array(semantic_map).astype(np.uint8)  

mask = onehot2mask(semantic_map.transpose(2,0,1))  
print(np.unique(mask)) # [ 0  1 15] 索引相对应的是背景、飞机、人  
print(mask.shape) # (375, 500)  

semantic_map = mask2onehot(mask, len(colormap))  
print(semantic_map.shape) # (21, 375, 500)