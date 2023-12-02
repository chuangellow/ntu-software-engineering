import React from "react";
import { Routes, Route } from "react-router-dom";
import Home from "./pages/Home";
import ViewItems from "./pages/ViewItems";
import UploadItems from "./pages/UploadItems";
import Login from "./pages/Login";
import Register from "./pages/Register";
import Profile from './pages/Profile';
import UpdateItem from './components/UpdateItem';
import ProtectedRoute from './ProtectedRoute';

const AppRoutes = () => {
  return (
    <Routes>
      <Route path="/" element={<Home />} />
      <Route path="/viewitems" element={
        <ProtectedRoute>
          <ViewItems />
        </ProtectedRoute>
      } />
      <Route path="/uploaditems" element={
        <ProtectedRoute>
          <UploadItems />
        </ProtectedRoute>
      } />
      <Route path="/login" element={<Login />} />
      <Route path="/register" element={<Register />} />
      <Route path="/profile" element={
        <ProtectedRoute>
          <Profile />
        </ProtectedRoute>
      } />
      <Route path="/UpdateItem" element={<UpdateItem />} />
    </Routes>
  );
};

export default AppRoutes;
